import cs50
import re


def main():
    text = input("text: ")

    # calls functions to get alpha chars, word count, and sentence count
    alpha = float(count_letters(text))
    words = float(count_words(text))
    sentences = float(count_sent(text))

    # values for readability equation
    letters = float(alpha / words * 100)
    sent_avg = float(sentences / words * 100)

    grade_lev = float(0.0588 * letters - 0.296 * sent_avg - 15.8)

    # print statements for specified conditions
    if (grade_lev >= 16):
        print("Grade 16+")
    elif (grade_lev <= 1):
        print("Before Grade 1")
    elif (grade_lev <= 15):
        print(f"Grade {round(grade_lev)}")


def count_letters(text):
    # function takes text from user and gives a count of characters in the text

    n = len(text)
    alpha = 0

    for i in text:
        if (i.isalpha()) == True:
            alpha += 1

    return alpha


def count_words(text):
    # function takes text from user and counts words in text

    count = 1
    n = len(text)

    for i in range(n):
        if (text[i].isspace()):
            count += 1
    # print(words)
    return count


def count_sent(text):
    # function counts sentences using regex library

    sents = len(re.split(r'[.!?]+', text))

    # print(sents)
    return sents - 1


main()