
def main():

    height = get_height()

    for i in range(height):
        print("#")

def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0:
                break
        except ValueError: # Very important piece of code that allows to vet for correct value type.
                print("Not an integer")
    return n

main()
