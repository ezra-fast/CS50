from cs50 import get_int # notice the specification of the functions(s) that we want to import here, it is NOT vague.
# If we just said "import cs50", when calling get_int we would have to specify that it is inside the cs50 library: [cs50.get_int]

x = get_int("x: ")
y = get_int("y: ")
print(x * y)
