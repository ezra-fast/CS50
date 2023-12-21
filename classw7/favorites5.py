import csv

from cs50 import SQL

db = SQL("sqlite:///favorites.db")

title = input("Title: ").strip()

rows = db.execute("SELECT COUNT(*) AS counter FROM favorites WHERE title LIKE ?", title) # ? is like %s in C

row = rows[0]

print(row["counter"])


# This program works.
# "Many-to-Many Relationships" in the lecture is a useful section that couldn't be replicated in VSCode.
# Coding atomically means to perform tasks instantaneously relative to other 'threads'
