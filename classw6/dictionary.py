words = set() # dict can also be used here, but adding items to it is more difficult, and is not as simple as line 13.

def check(word):
    if word.lower() in words: # This is converting [word] to lower.
        return True
    else:
        return False

def load(dictionary):
    file = open(dictionary, "r")
    for line in file:
        word = line.rstrip()
        words.add(word)
    file.close()
    return True

def size():
    return len(words)

def unload():
    return True

# This is the same program in Python as dictionary.c in C!
