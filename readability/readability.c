#include <stdio.h>
#include <cs50.h>
#include <ctype.h> // use the function: isalpha. use function isspace.
#include <string.h>
#include <math.h> // use the function round.

int main(void)
{

//Variables:

    int k;
    float letters = 0.0;
    int q;
    float words = 0.0;
    int d;
    float sentences = 0.0;
    float S = 0;
    float L = 0;
    int index_result;

//Functions:

    float count_letters(string text);
    float count_words(string text);
    float count_sentences(string text);
    float calculateL(float words, float letters);
    float calculateS(float sentences, float letters);
    int CL(float L, float S);

//Text Solicitation:

    string text = get_string("Text: ");

//Computing the letter, word, and sentence count for text:

    letters = count_letters(text);
    words = count_words(text);
    sentences = count_sentences(text);

//Turning letters, sentences, words into the values L and S:

    L = calculateL(letters, words);
    S = calculateS(sentences, words);

//Taking L and S and injecting them into the CL formula:

    index_result = CL(L, S);

//Printing the grade level produced by CL:

    if (index_result > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index_result < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index_result);
    }

//Declaring the variable length for the ensuing functions:

    int length = strlen(text);
}









float count_letters(string text)
{
    int k;
    int length = strlen(text);
    float letters = 0.0;
    for (k = 0; k < length; k++)
    {
        if (isalpha(text[k]))
        {
            letters++;
        }
    }
    return letters;
}




// use isspace in count_words.

float count_words(string text)
{
    int q;
    float words = 1.0;
    int length = strlen(text);

    for (q = 0; q < length; q = q + 1)
    {
        if (isspace(text[q]))
        {
            words = words + 1;
        }
    }
    return words;
}




float count_sentences(string text)
{
    int d;
    float sentences = 0;
    int length = strlen(text);

    for (d = 0; d < length; d++)
    {
        if ((text[d]) == '.' || (text[d]) == '?' || (text[d]) == '!')
        {
            sentences = sentences + 1;
        }
    }
    return sentences;
}

//Calculating the value of L:
float calculateL(float letters, float words)
{
    float L = (letters / words * 100);
    return L;
}

//Calculating the value of S:
float calculateS(float sentences, float words)
{
    float S = (sentences / words * 100);
    return S;
}

//Calculating CL with variables:

int CL(float L, float S)
{
    int index_result = round((0.0588 * L) - (0.296 * S) - 15.8);
    return index_result;
}


