from cs50 import get_string

s = get_string("Do you agree? ")

if s.lower() in ["y", "yes"]: # casting s to lower so that the list of possibilities does not have to be as exhaustive
    print("Agreed")
elif s == "N" or s == "n":
    print("Not agreed")
else:
    print("Y/y or N/n")

# You can append functions onto other function so long as they are appropriately contained.
# This possibility exists on line 3.
