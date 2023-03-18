from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0:
        break # Lines 3 - 6 are a deliberate infinite loop, and the program is instructed to break once a condition is met. (useful)


for i in range(n):
    print("#")


