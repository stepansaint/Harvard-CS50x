# A program that identifies a person based on their DNA
__author__ = "Ermakov Stepan"


import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Read database file into a list of dictionaries
    database = []
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            database.append(row)

    # Read DNA sequence file into a string
    with open(sys.argv[2], "r") as file:
        dna_sequence = file.read()

    # Remember only STRs in dictionary `suspect`
    suspect = dict(database[0])
    suspect.pop("name")

    # Find longest match of each STR in DNA sequence
    for STR in suspect:
        suspect[STR] = str(longest_match(dna_sequence, STR))

    # Check database for matching profiles
    # Print out the criminal, if there's one
    print(check_database(database, suspect))


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


def check_database(database, suspect):
    """Returns name of criminal, if there's one."""
    for profile in range(len(database)):
        matches = 0
        for STR in suspect:
            if suspect[STR] != database[profile][STR]:
                break
            matches += 1

            # Check whether profile's DNA matches all STRs
            if matches == len(suspect):
                criminal = database[profile]["name"]
                return criminal

    # If there's not enough matches
    return "No match"


if __name__ == "__main__":
    main()
