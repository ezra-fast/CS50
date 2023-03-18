from cs50 import get_int

def main():

    height = get_height()

    for i in range(height):
        print("#")

def get_height():
    while True:
        n = get_int("Height: ")
        if n > 0:
            break
    return n

main()
