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

    float alpha = count_letters(text);

    float words = count_words(text) + 1;

    float sentences = count_sentences(text);

    float letters = (alpha / words * 100);
    float savg = (sentences / words * 100);

    //printf("length %f words %f\n", letters, savg);
    //printf("alpha %f, words %f, sentences %f\n", alpha, words, sentences);

    float grade_level = 0.0588 * letters - 0.296 * savg - 15.8;

    if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade_level <= 1)
    {
        printf("Before Grade 1\n");
    }

    //uses round funtion call to round to the nearest int and not round down
    else if (grade_level <= 15)
    {
        printf("Grade %i\n", (int) round(grade_level));
    }
   // printf("%f alpha, %f words, %f sents", alpha, words, sentences);
}

int count_letters(string text)
{
    int n = strlen(text);
    int alpha = 0;

    for (int i = 0; i < n; i++)
    {
        if isalpha(text[i])
        {
            alpha++;
        }
    }
    return alpha;
}

//counts words
int count_words(string text)
{
    int n = strlen(text);
    int spaces = 0;

    for (int i = 0; i < n; i++)
    {
        if isspace(text[i])
        {
            spaces++;
        }
    }
    return spaces;
}

//counts sentences
int count_sentences(string text)
{
    int n = strlen(text);
    int sent = 0;

    for (int i = 0; i < n; i++)
    {
        if (text[i] == 46)
        {
            sent++;
        }
        if (text[i] == 33)
        {
            sent++;
        }
        if (text[i] == 63)
        {
            sent++;
        }
    }
    return sent;
}