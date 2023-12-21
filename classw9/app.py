from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/greet", methods=["POST"])
def greet():
    name = request.form.get("name", "world") # "world" in this case is a default value if the user does not provide any input
    return render_template("greet.html", name=name)


