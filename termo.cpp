#include <stdio.h>
#include <string.h>

#include <stdlib.h>

#include <time.h>

void qwerty(char[]);
int tamanho(char[]);
void ajustaQwerty(char[], char[], char[]);
void ajustaPalpite(char[]);
void feedback(char[], char[], int *);
void feedback2(char[], char[]);
bool existe(char, char[]);
void sorteio(char[]);

int main()
{

    char dailyWord[5];

    sorteio(dailyWord);
    puts(dailyWord);

    char alfabeto[26];

    for (int i = 0; i < 26; i++)
        alfabeto[i] = i + 65; // populei o alfabeto

    char palpite[5]; // criei a palavra diaria

    int corretas = 0;
    int chances = 5;

    printf("\n");

    do
    {

        qwerty(alfabeto);
        printf("\nDigite uma palavra de 5 letras: \n\n");
        gets(palpite);
        ajustaQwerty(alfabeto, dailyWord, palpite);
        system("cls");
        printf("\n\n\n");

        corretas = 0;
        feedback(dailyWord, palpite, &corretas);

        feedback2(dailyWord, palpite);

        chances--;
        printf("\n\n\nRestam %d chances!", chances);

    } while ((corretas < 5) && (chances > 0));

    if ((corretas == 5) && (chances > 0))
    {
        printf("\nPARABENS!!! Voce acertou. \n");
    }
    else if ((chances == 5) && (corretas != 5))
    {
        printf("\na palavra era %s. \n", dailyWord);
        printf("tente de novo amanha. \n");
    }

    return 0;
}

void qwerty(char alfa[])
{
    printf(" \n\n\n%c %c %c %c %c %c %c %c %c %c \n", alfa[16], alfa[22], alfa[4], alfa[17], alfa[19], alfa[24], alfa[20], alfa[8], alfa[14], alfa[15]);
    printf(" %c %c %c %c %c %c %c %c %c \n", alfa[0], alfa[18], alfa[3], alfa[5], alfa[6], alfa[7], alfa[9], alfa[10], alfa[11]);
    printf(" %c %c %c %c %c %c %c \n", alfa[25], alfa[23], alfa[2], alfa[21], alfa[1], alfa[13], alfa[12]);
}

void sorteio(char palavra[])
{
    char *palavras[1000] = {
        "sagaz", "amago", "termo", "negro", "exito", "mexer", "nobre", "senso", "afeto", "etica",
        "algoz", "plena", "fazer", "assim", "tenue", "mutua", "sobre", "aquem", "secao", "poder",
        "vigor", "sutil", "porem", "fosse", "cerne", "ideia", "sanar", "audaz", "moral", "inato",
        "quica", "desde", "muito", "justo", "sonho", "honra", "torpe", "razao", "amigo", "icone",
        "egide", "etnia", "futil", "anexo", "dengo", "tange", "haver", "lapso", "entao", "expor",
        "tempo", "banco", "bicho", "borda", "brisa", "bruxa", "cacho", "caixa", "calor", "campo",
        "canal", "canto", "capaz", "carga", "carne", "carro", "carta", "casal", "causa", "certo",
        "cinco", "claro", "corpo", "danca", "dardo", "dente", "diabo", "disco", "doido", "drama",
        "droga", "duplo", "durou", "elite", "email", "entre", "epoca", "estar", "etapa", "etica",
        "exame", "exato", "exito", "extra", "facil", "falar", "falso", "falha", "fauna", "fazer",
        "sagaz", "amago", "termo", "negro", "exito", "mexer", "nobre", "senso", "afeto", "etica",
        "algoz", "plena", "fazer", "assim", "tenue", "mutua", "sobre", "aquem", "secao", "poder",
        "vigor", "sutil", "porem", "fosse", "cerne", "ideia", "sanar", "audaz", "moral", "inato",
        "quica", "desde", "muito", "justo", "sonho", "honra", "torpe", "razao", "amigo", "icone",
        "egide", "etnia", "futil", "anexo", "dengo", "tange", "haver", "lapso", "entao", "expor",
        "tempo", "banco", "bicho", "borda", "brisa", "bruxa", "cacho", "caixa", "calor", "campo",
        "canal", "canto", "capaz", "carga", "carne", "carro", "carta", "casal", "causa", "certo",
        "cinco", "claro", "corpo", "danca", "dardo", "dente", "diabo", "disco", "doido", "drama",
        "droga", "duplo", "durou", "elite", "email", "entre", "epoca", "estar", "etapa", "etica",
        "exame", "exato", "exito", "extra", "facil", "falar", "falso", "falha", "fauna", "fazer",
        "sagaz", "amago", "termo", "negro", "exito", "mexer", "nobre", "senso", "afeto", "etica",
        "algoz", "plena", "fazer", "assim", "tenue", "mutua", "sobre", "aquem", "secao", "poder",
        "vigor", "sutil", "porem", "fosse", "cerne", "ideia", "sanar", "audaz", "moral", "inato",
        "quica", "desde", "muito", "justo", "sonho", "honra", "torpe", "razao", "amigo", "icone",
        "egide", "etnia", "futil", "anexo", "dengo", "tange", "haver", "lapso", "entao", "expor",
        "tempo", "banco", "bicho", "borda", "brisa", "bruxa", "cacho", "caixa", "calor", "campo",
        "canal", "canto", "capaz", "carga", "carne", "carro", "carta", "casal", "causa", "certo",
        "cinco", "claro", "corpo", "danca", "dardo", "dente", "diabo", "disco", "doido", "drama",
        "droga", "duplo", "durou", "elite", "email", "entre", "epoca", "estar", "etapa", "etica",
        "exame", "exato", "exito", "extra", "facil", "falar", "falso", "falha", "fauna", "fazer",
        "sagaz", "amago", "termo", "negro", "exito", "mexer", "nobre", "senso", "afeto", "etica",
        "algoz", "plena", "fazer", "assim", "tenue", "mutua", "sobre", "aquem", "secao", "poder",
        "vigor", "sutil", "porem", "fosse", "cerne", "ideia", "sanar", "audaz", "moral", "inato",
        "quica", "desde", "muito", "justo", "sonho", "honra", "torpe", "razao", "amigo", "icone",
        "egide", "etnia", "futil", "anexo", "dengo", "tange", "haver", "lapso", "entao", "expor",
        "tempo", "banco", "bicho", "borda", "brisa", "bruxa", "cacho", "caixa", "calor", "campo",
        "canal", "canto", "capaz", "carga", "carne", "carro", "carta", "casal", "causa", "certo",
        "cinco", "claro", "corpo", "danca", "dardo", "dente", "diabo", "disco", "doido", "drama",
        "droga", "duplo", "durou", "elite", "email", "entre", "epoca", "estar", "etapa", "etica",
        "exame", "exato", "exito", "extra", "facil", "falar", "falso", "falha", "fauna", "fazer",
        "sagaz", "amago", "termo", "negro", "exito", "mexer", "nobre", "senso", "afeto", "etica",
        "algoz", "plena", "fazer", "assim", "tenue", "mutua", "sobre", "aquem", "secao", "poder",
        "vigor", "sutil", "porem", "fosse", "cerne", "ideia", "sanar", "audaz", "moral", "inato",
        "quica", "desde", "muito", "justo", "sonho", "honra", "torpe", "razao", "amigo", "icone",
        "egide", "etnia", "futil", "anexo", "dengo", "tange", "haver", "lapso", "entao", "expor",
        "tempo", "banco", "bicho", "borda", "brisa", "bruxa", "cacho", "caixa", "calor", "campo",
        "canal", "canto", "capaz", "carga", "carne", "carro", "carta", "casal", "causa", "certo",
        "cinco", "claro", "corpo", "danca", "dardo", "dente", "diabo", "disco", "doido", "drama",
        "droga", "duplo", "durou", "elite", "email", "entre", "epoca", "estar", "etapa", "etica",
        "exame", "exato", "exito", "extra", "facil", "falar", "falso", "falha", "fauna", "fazer",
        "sagaz", "amago", "termo", "negro", "exito", "mexer", "nobre", "senso", "afeto", "etica",
        "algoz", "plena", "fazer", "assim", "tenue", "mutua", "sobre", "aquem", "secao", "poder",
        "vigor", "sutil", "porem", "fosse", "cerne", "ideia", "sanar", "audaz", "moral", "inato",
        "quica", "desde", "muito", "justo", "sonho", "honra", "torpe", "razao", "amigo", "icone",
        "egide", "etnia", "futil", "anexo", "dengo", "tange", "haver", "lapso", "entao", "expor",
        "tempo", "banco", "bicho", "borda", "brisa", "bruxa", "cacho", "caixa", "calor", "campo",
        "canal", "canto", "capaz", "carga", "carne", "carro", "carta", "casal", "causa", "certo",
        "cinco", "claro", "corpo", "danca", "dardo", "dente", "diabo", "disco", "doido", "drama",
        "droga", "duplo", "durou", "elite", "email", "entre", "epoca", "estar", "etapa", "etica",
        "exame", "exato", "exito", "extra", "facil", "falar", "falso", "falha", "fauna", "fazer",
        "sagaz", "amago", "termo", "negro", "exito", "mexer", "nobre", "senso", "afeto", "etica",
        "algoz", "plena", "fazer", "assim", "tenue", "mutua", "sobre", "aquem", "secao", "poder",
        "vigor", "sutil", "porem", "fosse", "cerne", "ideia", "sanar", "audaz", "moral", "inato",
        "quica", "desde", "muito", "justo", "sonho", "honra", "torpe", "razao", "amigo", "icone",
        "egide", "etnia", "futil", "anexo", "dengo", "tange", "haver", "lapso", "entao", "expor",
        "tempo", "banco", "bicho", "borda", "brisa", "bruxa", "cacho", "caixa", "calor", "campo",
        "canal", "canto", "capaz", "carga", "carne", "carro", "carta", "casal", "causa", "certo",
        "cinco", "claro", "corpo", "danca", "dardo", "dente", "diabo", "disco", "doido", "drama",
        "droga", "duplo", "durou", "elite", "email", "entre", "epoca", "estar", "etapa", "etica",
        "exame", "exato", "exito", "extra", "facil", "falar", "falso", "falha", "fauna", "fazer",
        "sagaz", "amago", "termo", "negro", "exito", "mexer", "nobre", "senso", "afeto", "etica",
        "algoz", "plena", "fazer", "assim", "tenue", "mutua", "sobre", "aquem", "secao", "poder",
        "vigor", "sutil", "porem", "fosse", "cerne", "ideia", "sanar", "audaz", "moral", "inato",
        "quica", "desde", "muito", "justo", "sonho", "honra", "torpe", "razao", "amigo", "icone",
        "egide", "etnia", "futil", "anexo", "dengo", "tange", "haver", "lapso", "entao", "expor",
        "tempo", "banco", "bicho", "borda", "brisa", "bruxa", "cacho", "caixa", "calor", "campo",
        "canal", "canto", "capaz", "carga", "carne", "carro", "carta", "casal", "causa", "certo",
        "cinco", "claro", "corpo", "danca", "dardo", "dente", "diabo", "disco", "doido", "drama",
        "droga", "duplo", "durou", "elite", "email", "entre", "epoca", "estar", "etapa", "etica",
        "exame", "exato", "exito", "extra", "facil", "falar", "falso", "falha", "fauna", "fazer",
        "sagaz", "amago", "termo", "negro", "exito", "mexer", "nobre", "senso", "afeto", "etica",
        "algoz", "plena", "fazer", "assim", "tenue", "mutua", "sobre", "aquem", "secao", "poder",
        "vigor", "sutil", "porem", "fosse", "cerne", "ideia", "sanar", "audaz", "moral", "inato",
        "quica", "desde", "muito", "justo", "sonho", "honra", "torpe", "razao", "amigo", "icone",
        "egide", "etnia", "futil", "anexo", "dengo", "tange", "haver", "lapso", "entao", "expor",
        "tempo", "banco", "bicho", "borda", "brisa", "bruxa", "cacho", "caixa", "calor", "campo",
        "canal", "canto", "capaz", "carga", "carne", "carro", "carta", "casal", "causa", "certo",
        "cinco", "claro", "corpo", "danca", "dardo", "dente", "diabo", "disco", "doido", "drama",
        "droga", "duplo", "durou", "elite", "email", "entre", "epoca", "estar", "etapa", "etica",
        "exame", "exato", "exito", "extra", "facil", "falar", "falso", "falha", "fauna", "fazer",
        "sagaz", "amago", "termo", "negro", "exito", "mexer", "nobre", "senso", "afeto", "etica",
        "algoz", "plena", "fazer", "assim", "tenue", "mutua", "sobre", "aquem", "secao", "poder",
        "vigor", "sutil", "porem", "fosse", "cerne", "ideia", "sanar", "audaz", "moral", "inato",
        "quica", "desde", "muito", "justo", "sonho", "honra", "torpe", "razao", "amigo", "icone",
        "egide", "etnia", "futil", "anexo", "dengo", "tange", "haver", "lapso", "entao", "expor",
        "tempo", "banco", "bicho", "borda", "brisa", "bruxa", "cacho", "caixa", "calor", "campo",
        "canal", "canto", "capaz", "carga", "carne", "carro", "carta", "casal", "causa", "certo",
        "cinco", "claro", "corpo", "danca", "dardo", "dente", "diabo", "disco", "doido", "drama",
        "droga", "duplo", "durou", "elite", "email", "entre", "epoca", "estar", "etapa", "etica",
        "exame", "exato", "exito", "extra", "facil", "falar", "falso", "falha", "fauna", "fazer"};

    srand(time(NULL));

    int sort = rand() % 1000;

    strcpy(palavra, palavras[sort]);
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
                if ((alfa[i] == palp[j]) || (alfa[i] + 32 == palp[j]))
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

            *corretas = *corretas + 1;

            printf("%c ", palp[i]);
        }
        else
        {
            printf("%c ", 95);
        }
    }
}

void feedback2(char p[], char palp[])
{

    for (int i = 0; i < 5; i++)
    {

        if ((p[i] != palp[i]) && (existe(palp[i], p)))
        {
            printf("\n\nExiste um '%c' na palavra. ", palp[i]);
        }
    }
}

void ajustaPalpite(char palp[])
{

    int i = 0;

    while (palp[i] != '\0')
    {
        if (palp[i] > 96)
        {
            palp[i] = palp[i] - 32;
        }

        i++;
    }
}