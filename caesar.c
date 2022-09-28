#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool valid_k(string s);

int main(int argc, string argv[1])

{
// checar se o numero de argumentos é diferente de 2 e se a booleana para argv[1]
//é verdadeira.
    if (argc != 2 || !valid_k(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // atoi para transpor o valor de texto para inteiro
    int k = atoi(argv[1]);

    string plaintext = get_string("Plaintext:");
    printf("Ciphertext:");

// definindo o char len como a stringlength do plaintext prompatado pelo user
// e verificando se esse caracter for alfabético, minusculo ou maiusculo.
    char len = strlen(plaintext);
    for (int i = 0; i < len; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            char mod = 'A';
            if (islower(c))
            {
                mod = 'a';
            }
            printf("%c", (c - mod + k) % 26 + mod);
        }

        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
    printf("You enciphered the message\n");
}

// verificando se qualquer caracter que não seja um digito então deve retornar falso.
bool valid_k(string s)

{
    char len = strlen(s);
    for (int i = 0; i < len; i++)

        if (!isdigit(s[i]))
        {
            return false;
        }
    return true;
}
