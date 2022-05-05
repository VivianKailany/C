#include <stdio.h>
#include <cs50.h>
#include <math.h>

bool var(long long CC);
int tam_cart(long long k);
bool checksum(long long cnn);
void bandeira_cart(long long cnn);

//Guarda variavel do usuario
int main(void)
{
    long long CC;
    do
    {
        CC = get_long_long("numero: ");  
    }
//Verifica a variavel
    while (CC < 0);
    if (var(CC) == true)
    {
        bandeira_cart(CC);
    }
    else
    {
        printf("INVALID\n");
    }
}
bool var(long long CC)
{
    int tam = tam_cart(CC);
    return (tam == 13 || tam == 15 || tam == 16) && checksum(CC);
}

int tam_cart(long long k)
{
    int tam;
    for (tam = 0; k != 0; k /= 10, tam++);
    return tam;
}
//Verificando a variavel de acordo com padroes de um cartao       
bool checksum(long long cnn) 
{
    int s = 0;
    for (int i = 0; cnn != 0; i++, cnn /= 10)
    {
        if (i % 2 == 0)
        {
            s += cnn % 10;
        }
        else
        {
            int digito = 2 * (cnn % 10);
            s += digito / 10 + digito % 10 ;

        }

    }
        
    return (s % 10) == 0;
}
//Classifica a variavel    
void bandeira_cart(long long cnn)
{
    if ((cnn >= 34e13 && cnn < 35e13) || (cnn >= 37e13 && cnn < 38e13))
    {
        printf("AMEX\n");
    }
    else if (cnn >= 51e14 && cnn < 56e14)
    {
        printf("MASTERCARD\n");
    }
    else if ((cnn >= 4e12 && cnn < 5e12) || (cnn >= 4e15 && cnn < 5e15))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
