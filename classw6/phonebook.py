from cs50 import get_string
import sys

# The people array here is an example of key-value pairs

people = {
    "Carter": "+1-617-495-1000", # Here, "David" is the key, "+1-617-495-1000" is the corresponding value.
    "David": "+1-949-468-2750"
}

name = get_string("Name: ")
if name in people:
    print(f"Number: {people[name]}")
else:
    print("Not found.")
    sys.exit(1)

sys.exit(0)
