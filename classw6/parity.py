from cs50 import get_int

n = get_int("x: ")

if n % 2 == 0:
    print("The integer is even")
elif n % 2 != 0:
    print("The integer is odd")

