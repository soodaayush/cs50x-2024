import cs50


def count_letters(text):
    n = len(text)
    letters = 0

    for i in range(n):
        if text[i].isalpha():
            letters += 1

    return letters


def count_words(text):
    n = len(text)
    words = 1

    for i in range(n):
        if text[i] == " ":
            words += 1

    return words


def count_sentences(text):
    n = len(text)
    sentences = 0

    for i in range(n):
        if text[i] == "." or text[i] == "?" or text[i] == "!":
            sentences += 1

    return sentences


text = cs50.get_string("Text: ")

letters = count_letters(text)
words = count_words(text)
sentences = count_sentences(text)

averageLetters = letters / words * 100
averageSentences = sentences / words * 100

index = round(0.0588 * averageLetters - 0.296 * averageSentences - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f'Grade {index}')
