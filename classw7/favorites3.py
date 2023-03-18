import csv
import re

counter = 0

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["title"].strip().upper()
        if re.search("^(OFFICE|THE.OFFICE)$", title): # re.search("needle", haystack)
            counter += 1


print(f"Number of people who like The Office: {counter}")
