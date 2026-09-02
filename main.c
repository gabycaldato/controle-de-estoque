#include "biblioteca.h"

int main()
{
    int opcao;

    printf("=====Bem vindo======\n");

    do
    {
        opcao = opcoes();

        switch (opcao)
        {
        case 1:
            system("cls");

            adicionarPro();
            printf("Aperte enter para continuar...");
            fflush(stdin);
            scanf("%c");
            break;
        case 2:
            system("cls");

            mostrarPro();
            printf("Aperte enter para continuar...");
            fflush(stdin);
            scanf("%c");
            break;
        case 3:
            system("cls");

            editarPro();
            printf("Aperte enter para continuar...");
            fflush(stdin);
            scanf("%c");
            break;
        case 4:
            system("cls");

            excluirPro();
            printf("Aperte enter para continuar...");
            fflush(stdin);
            scanf("%c");
            break;
        case 5:
            system("cls");

            procurarPro();
            printf("Aperte enter para continuar...");
            fflush(stdin);
            scanf("%c");
            break;
        case 6:
            system("cls");

            sair();
            break;

        default:
            printf("Opcao invalida, tente novamente.\n");
            printf("Aperte enter para continuar...");
            fflush(stdin);
            scanf("%c");
            break;
        }

        system("cls");
    } while (1);

    return 0;
}