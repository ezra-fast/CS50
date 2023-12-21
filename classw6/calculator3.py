from cs50 import get_int

x = get_int("x: ")
y = get_int("y: ")

z = (x / y) # cast this to an int if you do not want to have a decimal value in the answer
print(f"{z:.50f}") # this notation specifices desired numbered of significant digits

