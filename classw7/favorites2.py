import csv

titles = {}

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["title"].strip().upper()
        if title in titles:
            titles[title] += 1
        else:
            titles[title] = 1


# def get_value(title):
    # return titles[title]


for title in sorted(titles, key=lambda title: titles[title], reverse=True):
    print(title, titles[title])





# This code filters out duplicates by removing whitespace and different capitalizations


# Minute 12 in lecture 7 has VERY USEFUL INFORMATION


# By using DictReader, we are turning the data into "dictionary objects", which can be indexed into using the key to the desired value,
# which is title in the case of line 6. (Consult line 16 for instruction)
