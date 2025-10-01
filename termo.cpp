#include <stdio.h>
#include <string.h>

void qwerty(char[]);
int tamanho(char[]);
void ajustaQwerty(char[], char[], char[]);
void feedback(char[], char[], int *);
bool existe(char, char[]);

int main()
{
    char alfabeto[26];

    for (int i = 0; i < 26; i++)
        alfabeto[i] = i + 65; // populei o alfabeto

    char dailyWord[5], palpite[5]; // criei a palavra diaria

    dailyWord[0] = 'F';
    dailyWord[1] = 'A';
    dailyWord[2] = 'Z';
    dailyWord[3] = 'E';
    dailyWord[4] = 'R';

    int corretas = 0;
    int chances = 0;

    printf("\n");

    do
    {
        printf("\n\nDigite uma palavra de 5 caracteres: \n\n");
        qwerty(alfabeto);
        gets(palpite);

        ajustaQwerty(alfabeto, dailyWord, palpite);

        feedback(dailyWord, palpite, &corretas);

        chances++;

    } while ((corretas < 5) && (chances < 5));

    if ((corretas == 5) && (chances < 6))
    {
        printf("\nvoce venceu!!!!! \n");
    }
    else if ((corretas < 5) && (chances < 4))
    {
        printf("\nmais uma chance! \n");
        printf("\n letras disponiveis: \n");
        corretas = 0;
    }
    else if ((chances == 5) && (corretas != 5))
    {
        printf("\na palavra era FAZER. \n");
        printf("tente de novo amanha. \n");
    }
}

void qwerty(char alfa[])
{
    printf(" \n%c %c %c %c %c %c %c %c %c %c \n", alfa[16], alfa[22], alfa[4], alfa[17], alfa[19], alfa[24], alfa[20], alfa[8], alfa[14], alfa[15]);
    printf(" %c %c %c %c %c %c %c %c %c \n", alfa[0], alfa[18], alfa[3], alfa[5], alfa[6], alfa[7], alfa[9], alfa[10], alfa[11]);
    printf(" %c %c %c %c %c %c %c \n\n\n", alfa[25], alfa[23], alfa[2], alfa[21], alfa[1], alfa[13], alfa[12]);
}

int tamanho(char palavra[])
{

    int i = 0;

    while (palavra[i] != '\0')

        i++;

    return i;
}

void ajustaQwerty(char alfa[], char p[], char palp[])
{

    for (int j = 0; j <= 5; j++)
    {

        if ((palp[j] != p[0]) && (palp[j] != p[1]) && (palp[j] != p[2]) && (palp[j] != p[3]) && (palp[j] != p[4]))
        {

            for (int i = 0; i < 26; i++)
            {
                if (alfa[i] == palp[j])
                {
                    alfa[i] = '_';
                }
            }
        }
    }
}

bool existe(char letra, char palavra[])
{

    int i = 0;

    while (palavra[i] != '\0')
    {
        if ((palavra[i] == letra) || (palavra[i] - 32 == letra))
        {
            return true;
        }
        i++;
    }
    return false;
}

void feedback(char p[], char palp[], int *corretas)
{

    for (int i = 0; i < 5; i++)
    {

        if (p[i] == palp[i])
        {
            *corretas++;
            printf("%c ", palp[i]);
        }
        else
        {

            printf("%c ", 95);
        }
    }
}