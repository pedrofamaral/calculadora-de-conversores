//Pedro Henrique Franco Moreira Amaral
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <windows.h>

int bin2dec(long long binario);
long long dec2bin(int decimal);


int main()
{
    char opc = ' ', hexa[100];
    long long binario;
    int sequencial, n1, tamanho_string, decimal, cociente;

    do
    {
        system("cls");
        printf("=====conversor=====\n");
        printf("Digite a Opcao\n");
        printf("1 - Binario para Decimal\n");
        printf("2 - Decimal para Binario\n");
        printf("3 - Decimal para Hexa\n");
        printf("4 - Hexa para Decimal\n");
        printf("5 - Sair\n");
        printf("Resposta: ");
        scanf("%d", &opc);
        getchar();
        switch(opc)
        {
            case 1:printf("Digite um numero binario = ");
                   scanf("%lld", &binario);
                   printf("%lld em binario = %d em decimal\n", binario, bin2dec(binario));
                   break;

            case 2:printf("Digite um numero decimal = ");
                   scanf("%d", &decimal);
                   printf("%d em decimal = %lld em binario\n", decimal, dec2bin(decimal));
                   break;

            case 3:printf("Digite um numero decimal = ");
                   scanf("%d", &decimal);
                   sequencial = 0;
                   cociente = decimal;


                   while (cociente != 0) {
                   n1 = cociente % 16;
                   if( n1 < 10)
                   n1 = n1 + 48;
                   else
                   n1 = n1 + 55;

                   hexa[sequencial++] = n1;

                   cociente = cociente / 16;
            }
                   hexa[sequencial++] = '\0';
                   printf("%d em decimal = %s em hexa\n", decimal, hexa);
                   break;

            case 4:
                   decimal = 0;
                   printf("Digite um numero hexadecimal = ");
                   gets(hexa);


                tamanho_string = strlen(hexa);
                tamanho_string--;

                for (sequencial = 0; hexa[sequencial] != '\0'; sequencial++) {
                    if (hexa[sequencial] >= '0' && hexa[sequencial] <= '9') {
                        n1 = hexa[sequencial] - '0';
                    }
                    else if (hexa[sequencial] >= 'a' && hexa[sequencial] <= 'f') {
                        n1 = hexa[sequencial] - 'a' + 10;
                    }
                    else if (hexa[sequencial] >= 'A' && hexa[sequencial] <= 'F') {
                        n1 = hexa[sequencial] - 'A' + 10;
                    }

                    decimal += n1 * pow(16, tamanho_string);
                    tamanho_string--;
                }
                printf("%s em hexa = %d em decimal\n", hexa, decimal);
                break;
            case 5:printf("Saindo...\n\n");
                   break;
                   default: printf("Opcao invalida\n");
        }
        system("pause");
    }while (opc != 5);


}
int bin2dec(long long binario)
{
    int decimal = 0, sequencial = 0, resto;

    while (binario != 0)
    {
        resto = binario % 10;
        binario /= 10;
        decimal += resto * pow(2, sequencial);
        ++sequencial;
    }

    return decimal;
}


long long dec2bin(int decimal)
{
    long long binario = 0;
    int resto, sequencial = 1;


    while (decimal != 0)
    {
        resto = decimal % 2;
        decimal /= 2;
        binario += resto * sequencial;
        sequencial *= 10;
    }

    return binario;
}





