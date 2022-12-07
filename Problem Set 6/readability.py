# A program that calculates the approximate grade level
# needed to comprehend some text
__author__ = "Ermakov Stepan"


def main():

    # Get user's input
    text = input("Text: ")

    # Count each part of Coleman-Liau index
    PER_100_WORDS = 100
    average_letters = float(count_letters(text)) / count_words(text) * PER_100_WORDS
    average_sentences = float(count_sentences(text)) / count_words(text) * PER_100_WORDS

    # The Coleman-Liau index of a text is designed to output that
    # (U.S.) grade level that is needed to understand some text
    index = round(0.0588 * average_letters - 0.296 * average_sentences - 15.8)

    # Print grade reading level for user's text
    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


def count_letters(text):
    """Count letters in the text. Return number of letters."""
    letters = 0
    for i in text:
        if i.isalpha():
            letters += 1
    return letters


def count_sentences(text):
    """Count sentences in the text. Return number of sentences."""
    sentences = 0
    for char in text:
        if char == '.' or char == '!' or char == '?':
            sentences += 1
    return sentences


def count_words(text):
    """Count words in the text. Return number of words."""
    return len(text.split())


if __name__ == "__main__":
    main()
