from cs50 import get_int, get_string


string = input("Input: ")
if string.isupper() == True:
    print('Does not contain lowercase letter.')
else:
    print('Contains lowercase letter.')


