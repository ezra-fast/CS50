
try: # "try this"
    x = int(input("x: ")) # By default, input defines input as a string
except ValueError: # "if there is an exception, do this:"
    print("That is not an int")
    exit()
try:
    y = int(input("y: ")) # in this instance, int is acting as a function
except:
    print("That is not an int")
    exit()
print(x * y)
