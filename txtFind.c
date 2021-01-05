#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define WORD 30
#define LINE 256
int getLine(char s[]);
int getword(char w[]);
int similar(char *s, char *t, int n);
int substring(char *str1, char *str2);
void print_similar_words(char *str);
void print_lines(char *str);

int getword(char *w)
{
    // int i = 0;
    // char c;
    // while (!isspace(c = getchar()) && c != EOF)
    // {
    //     w[i] = c;
    //     i++;
    // }
    // w[i] = 0;
    // if (c != EOF)
    //     return i + 1;
    // return i;

    char letter = getchar();
    int currentSize = 0;
    while (!isspace(letter))
    {
        w[currentSize] = letter;
        letter = getchar();
        currentSize++;
    }
    w[currentSize] = '\0';
    if (letter != EOF)
    {
        return ++currentSize;
    }

    return currentSize;
}
// check if s similiar to t(if we delete n letters from s we'll get t)
int similar(char *s, char *t, int n)
{
    int x = strlen(s);
    int y = strlen(t);
    if (x != y + n)
    {
        return 0;
    }
    int i = 0;
    int j = 0;
    int mistakes = 0;
    while (*(s + i) != '\0' && *(s + i) != '\n')
    {
        if (*(s + i) == *(t + j))
        {
            i++;
            j++;
        }
        else
        {
            mistakes++;
            i++;
            if (mistakes > n)
            {
                return 0;
            }
        }
    }
    return 1;
}

int getLine(char s[])
{
    char letter = getchar();
    int currentSize = 0;
    while (letter == '\n')
    {
        letter = getchar();
    }
    if (letter == EOF)
    {
        return 0;
    }
    while (currentSize < LINE && letter != '\n' && letter != '\r' && letter != EOF)
    {
        s[currentSize] = letter;
        currentSize++;
        letter = getchar();
    }
    s[currentSize] = '\0';
    return currentSize;
}

//fix it
//check if str1 conatins str2
int substring(char *str1, char *str2)
{
    int i = 0;

    while (*str1 != '\0' && *str1 != '\n' && *str1 != '\r')
    {
        if (*str1 == *(str2 + i))
        {
            i++;

            if (i == strlen(str2))
            {
                return 1;
            }
        }
        else
        {
            i = 0;
        }
        str1++;
    }
    return 0;
}
void print_similar_words(char *str)
{
    char s[WORD];
    int i = getword(s);
    while (i != 0)
    {

        if (similar(s, str, 1) || similar(s, str, 0))
        {
            printf("%s\n", s);
        }
        i = getword(s);
    }
}
void print_lines(char *str)
{
    char s[LINE];
    int length = getLine(s);
    while (length != 0)
    {
        if (substring(s, str) == 1)
        {
            printf("%s\n", s);
        }
        length = getLine(s);
    }
}
int main()
{
    char firstword[WORD];
    getword(firstword);

    char choice;
    scanf(" %c\n", &choice);

    if (choice == 'a')
    {

        print_lines(firstword);
    }
    else
    {
        if (choice == 'b')
        {

            print_similar_words(firstword);
        }
    }
}