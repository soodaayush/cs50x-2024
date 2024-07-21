#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    double averageLetters = letters / (float) words * 100;
    double averageSentences = sentences / (float) words * 100;

    int index = round(0.0588 * averageLetters - 0.296 * averageSentences - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int n = strlen(text);
    int letters = 0;

    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
            letters++;
    }

    return letters;
}

int count_words(string text)
{
    int n = strlen(text);
    int words = 1;

    for (int i = 0; i < n; i++)
    {
        if (text[i] == ' ')
            words++;
    }

    return words;
}

int count_sentences(string text)
{
    int n = strlen(text);
    int sentences = 0;

    for (int i = 0; i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
            sentences++;
    }

    return sentences;
}
