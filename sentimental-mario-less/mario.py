# TODO

from cs50 import get_int


def main():

    height = int(get_int("Height: "))

    if height <= 0 or height > 8 or height == -1:  # Covering all bases for invalid input
        height = int(get_int("Height: "))

    for i in range(height):  # looping through 'height' number of times
        print((height - 1 - i) * " ", end="")  # Printing required spaces
        print((1 + i) * "#")  # Printing required number of hashes


main()
