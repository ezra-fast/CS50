import sys

numbers = [4, 6, 8, 2, 7, 5, 0]

if 0 in numbers: # Linear search here is automatic in Python, built right in
    print("Found")
    sys.exit(0)

print("Not Found")
sys.exit(1)
