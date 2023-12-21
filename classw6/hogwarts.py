import csv

# CURRENTLY PHONEBOOK.CSV DOES NOT HAVE THE APPROPRIATE DATA IN IT TO RUN THIS PROGRAM!

houses = {
    "Gryffindor": 0,
    "Hufflepuff": 0,
    "Ravenclaw": 0,
    "Slytherin": 0
}

with open("phonebook.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        house = row["House"] # row["House"] here (reference lecture) refers to the [1] or ["House"] array position of a line from a csv file,
        # because the initial value is [0] and after the comma is [1], typically also specified in the csv file itself.
        houses[house] += 1

for house in houses:
    count = houses[house]
    print(f"{house}: {count}")

# This example can be found at 2:05:00 in Lecture 6.
