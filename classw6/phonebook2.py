import csv # "Comma Seperated Values"
from cs50 import get_string

file = open("phonebook.csv", "a")

name = get_string("Name: ")
number = get_string("Number: ")

writer = csv.writer(file)
writer.writerow([name, number])

file.close()
# This file is appending names and numbers into a csv file, called phonebook.csv

# an abstracted version of this code can be found at 2:08:30 in Lecture #6