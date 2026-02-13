#include "biblioteca.h"

int main(){
    int opcao;

    printf("=====Bem vindo======\n");

    do{
        opcao = opcoes();
        
        switch (opcao)
        {
            case 1:
                adicionarPro();
                break;
            case 2:
                mostrarPro();
                break;
            case 3:
                editarPro();
                break;
            case 4:
                excluirPro();
                break;
            case 5:
                procurarPro();
                break;
            case 6:
                sair();
                break;
            
            default:
                printf("Opcao invalida, tente novamente.\n");
                break;
        }

    }while(1);

    return 0;
}