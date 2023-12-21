from sys import argv

if len(argv) == 2:
    print(f"Hello, {argv[1]}")
else:
    print("hello, world")

# file.py is considered the first command line argument, so the name is argv[1], (the second arugment)

for arg in argv[1:]: # Here, 1: is "slicing the list", meaning that it is beginning somewhere other than the start
    print(arg)

# for line 10, :-1 would cut off the last value in the list
