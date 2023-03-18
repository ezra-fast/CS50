import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Incorrect Program Usage")
        sys.exit(1)

    # TODO: Read database file into a variable

    filename = sys.argv[1]

    database = []

    with open(filename, "r") as file:
        reader = csv.reader(file)
        for row in reader:
            database.append(row)
        key = database[0:1][0]  # Referenced 2 lines below
        key = key[1:]

        # Here we are taking the database and removing the top line, which we have turned into the key called "key"
        database = database[1:]

    # TODO: Read DNA sequence file into a variable

    with open(sys.argv[2], "r") as file1:
        reader1 = csv.reader(file1)
        sequence = file1.read()  # 'sequence' is a string that contains the whole of the DNA sequence

    # TODO: Find longest match of each STR in DNA sequence
    counter = 0
    matches = {}

    while counter < len(key):
        match = longest_match(sequence, key[counter])
        matches[key[counter]] = match
        counter += 1

    # TODO: Check database for matching profiles

    for x in database:
        if (int(x[1])) == matches["AGATC"] and (int(x[3])) == matches["AATG"] and (int(x[6])) == matches["TATC"]:
            print(x[0])
            sys.exit(0)

    print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
