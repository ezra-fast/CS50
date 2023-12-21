import os

from cs50 import SQL, get_string
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/") # This is "index"
@login_required
def index():
    """Show portfolio of stocks"""

    # Getting current user_id:
    user_id = session["user_id"]

    # Getting info in format list of dicts:
    info = db.execute("select symbol, stock_name, price, shares from transactions where user_id = ? AND shares > 0 group by symbol", user_id)

    # Ensuring that the user has holdings:
    if not info:
        return apology("No Valid Holdings", 200)

    # Turning the users cash into a variable:
    user_cash = db.execute("select cash from users where id = ?", user_id)
    user_cash = user_cash[0]["cash"]

    # Configuring Total Holdings Value + user_cash:
    total_value = user_cash

    # Changing price of stocks to current price and incrementing total holdings + cash value:
    for holding in info:
        price = lookup(holding["symbol"])
        price = price["price"]
        holding["price"] = price
        quantity = holding["shares"]
        holding_value = price * quantity
        total_value = total_value + holding_value

    return render_template("index.html", info=info, remaining_cash=user_cash, total_value=total_value)

@app.route("/buy", methods=["GET", "POST"]) # This is "buy"
@login_required
def buy():
    """Buy shares of stock"""

    # Getting "GET" out of the way:
    if request.method == "GET":
        return render_template("buy.html")

    # If the method is "POST":
    elif request.method == "POST":

        # if lookup(symbol) comes back invalid:
        if not lookup(request.form.get("symbol")):
            return apology("Invalid Stock.")

        # Ensuring that the number of shares is possible:
        temp_shares = int(request.form.get("shares"))
        if temp_shares < 1:
            return apology("Number of Shares Not Possible.")

        # declaring the number of shares and the stock info (stock info is stored in dictionary format):
        num_shares = request.form.get("shares")
        num_shares = int(num_shares)
        stock_symbol = request.form.get("symbol")
        stock_info = lookup(stock_symbol)

        price = stock_info["price"]
        name = stock_info["name"]
        symbol = stock_info["symbol"]

        cost_total = num_shares * price

        # declaring the current users id:
        user_id = session["user_id"]

        # finding current users balance:
        user_balance = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        user_balance = float(user_balance[0]["cash"])

        # Verifying that user has enough cash to process the transaction:
        if cost_total > user_balance:
            return apology("Insufficient Cash")

        # Putting into database:
        new_no_shares = db.execute("select shares from transactions where symbol = ?", symbol)
        if not new_no_shares:
            new_no_shares = num_shares
        else:
            new_no_shares = int(new_no_shares[0]["shares"])
            new_no_shares = new_no_shares + num_shares
        symbol_check = db.execute("select symbol from transactions where symbol = ?", symbol)
        if symbol_check:
            symbol_check = symbol_check[0]["symbol"]
        if symbol in symbol_check:
            db.execute("update transactions set shares = ?, transacted = datetime('now', 'localtime'), price = ? where symbol = ?", new_no_shares, price, symbol)
        else:
            db.execute("INSERT INTO transactions (symbol, stock_name, shares, price, transacted, user_id) VALUES(?, ?, ?, ?, datetime('now', 'localtime'), ?)", stock_symbol, name, num_shares, price, user_id)

        # Removing appropriate amount of cash from users bank account:
        adjusted_amount = (user_balance - cost_total)
        adjusting_cash = db.execute("UPDATE users SET cash = ? WHERE id = ?", adjusted_amount, user_id)


        # This is the history component for table and function:

        buy_status = "bought"

        logging_history = db.execute("insert into history (price, symbol, shares, status, user_id, timedate) VALUES (?, ?, ?, ?, ?, datetime('now', 'localtime'))", price, symbol, num_shares, buy_status, user_id)


        # Redirecting after putting into database:
        return redirect("/")



@app.route("/history") # This is "history"
@login_required
def history():
    """Show history of transactions"""

    user_id = session["user_id"]

    history = db.execute("select * from history where user_id = ? ORDER BY timedate", user_id)

    return render_template("history.html", history=history)



@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"]) # This is "quote"
@login_required
def quote():
    """Get stock quote."""

    if request.method == "GET":
        return render_template("quote.html")
    elif request.method == "POST":
        input = request.form.get("symbol")
        if not lookup(input):
            return apology("Invalid Stock.")
        stockinfo = lookup(input)

        name = stockinfo["name"]
        symbol = stockinfo["symbol"]
        price = stockinfo["price"]
        price = usd(price)

        return render_template("quoted.html", name=name, symbol=symbol, price=price)



@app.route("/register", methods=["GET", "POST"]) # This is "register"
def register():
    """Register user"""

    if request.method == "POST":
        if not request.form.get("username") or not request.form.get("password") or not request.form.get("confirmation") or request.form.get("password") != request.form.get("confirmation"):
            return apology("User Error", 400)

        username = request.form.get("username")
        password = generate_password_hash(request.form.get("password"))

        insert = db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, password)

        if not insert:
            return apology("Username Taken", 400)

        user_info = db.execute("SELECT * FROM users WHERE username = ?", username)

        session["user_id"] = user_info[0]["id"]

        return redirect("/")

    else:
        return render_template("register.html")



@app.route("/sell", methods=["GET", "POST"]) # This is "sell"
@login_required
def sell():
    """Sell shares of stock"""

    # Covering GET request method:
    if request.method == "GET":

        # Current User ID:
        user_id = session["user_id"]

        # Variabalizing stock symbols:
        symbols = db.execute("select * from transactions where user_id = ? and shares > 0 group by symbol", user_id)

        # Returning template with list of dicts:
        return render_template("sell.html", symbols=symbols)

    # Covering POST request method:
    elif request.method == "POST":

        # Number of shares:
        number = request.form.get("shares")
        number = int(number)

        # Ensuring proper amount of stocks:
        if number < 1:
            return apology("Insufficient Number of Shares.")

        # Variabalizing stock symbol:
        symbol = request.form.get("symbol")

        # Ensuring symbol exists:
        if not symbol:
            return apology("No Valid Symbol")

        # Current price:
        price = lookup(symbol)
        price = price["price"]
        price = float(price)

        # Amount to add to account:
        adding_amount = price * number

        # Calculating new cash balance:
        user_id = session["user_id"]
        user_cash = db.execute("select cash from users where id = ?", user_id)
        user_cash = float(user_cash[0]["cash"])
        new_amount = user_cash + adding_amount

        # Adding new_amount to user account:
        adding = db.execute("update users set cash = ? where id = ?", new_amount, user_id)

        # Updating holding numbers to reflect sale (taking away sold stocks):
        pre_sale_shares = db.execute("select shares from transactions where symbol = ? AND user_id = ?", symbol, user_id)
        pre_sale_shares = pre_sale_shares[0]["shares"]
        pre_sale_shares = int(pre_sale_shares)
        post_sale_shares = pre_sale_shares - number
        taking_away = db.execute("update transactions set shares = ? where user_id = ? AND symbol = ?", post_sale_shares, user_id, symbol)



        # This is for History table and function:

        transaction_status = "sold"

        documenting_history = db.execute("insert into history (price, symbol, shares, status, user_id, timedate) VALUES (?, ?, ?, ?, ?, datetime('now', 'localtime'))", price, symbol, number, transaction_status, user_id)

        return redirect("/")
