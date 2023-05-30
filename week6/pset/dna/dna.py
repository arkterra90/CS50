import csv
import sys


def main():

    # checks for correct amount of command line arguments
    if len(sys.argv) != 3:
        print("Usage: python dna.py FILENAME")
        sys.exit(1)

    # reads csv into list database
    with open(sys.argv[1], "r") as file:
        reader = csv.reader(file)
        dna_database = list(reader)

    # reads .txt file into variable
    with open(sys.argv[2], "r") as dna_file:
        dna_seq = dna_file.read()

    # finds longest match comparing .txt file variable and dna_database
    # by calling the longest_match function and iterating through dna_database
    dna_chain = []

    row_len = len(dna_database[0])
    for i in range(1, row_len):
        dna_chain.append(longest_match(dna_seq, dna_database[0][i]))

    # checks dna_database against dna_chain by iterating through
    # finds name of dna_database match if any found else exits program
    # and prints "No Match"
    match = 0

    for i in range(1, len(dna_database)):
        for j in range(len(dna_chain)):

            if int(dna_database[i][j+1]) == dna_chain[j]:
                match += 1

        if match == len(dna_chain):
            print(str(dna_database[i][0]))
            sys.exit(0)

        else:
            match = 0

    print("No Match")
    sys.exit(0)

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
