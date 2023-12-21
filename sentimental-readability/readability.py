# TODO

from cs50 import get_string


def main():

    text = get_string("Text: ")

    letters = 0
    words = 1
    sentences = 0

    S = 0.0
    L = 0.0

    CLI = 0.0

# Here we are calculating letters:
    for i in text:
        if ord(i) >= 65 and ord(i) <= 90 or ord(i) <= 122 and ord(i) >= 97:
            letters = letters + 1

# Here we are calculating words:
    for k in text:
        if ord(k) == 32:
            words = words + 1


# Here we are calculating sentences:
    for u in text:
        if u == "?" or u == "." or u == "!":
            sentences = sentences + 1


# Here we are calculating the value of L:
    L = (letters / words) * 100

# Here we are calculating the value of S:
    S = (sentences / words) * 100

# Here we are calculating the value of CLI:
    CLI = ((0.0588 * L) - (0.296 * S) - 15.8)

    CLI = round(CLI)


# Here we are printing the result:
    if CLI > 15:
        print("Grade 16+")
    elif CLI < 1:
        print("Before Grade 1")
    else:
        print(f"Grade: {CLI}")


main()
