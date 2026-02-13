#include <stdio.h>
#include <stdlib.h> 
#include "biblioteca.h"

struct estoque
{
    int id;
    char nome[75];
    int quantidade;
    float preco;
};

int opcoes(){

    printf("\n===================================\n");    
    printf("[1] - Adicionar produto\n");
    printf("[2] - Mostrar produto(s)\n");
    printf("[3] - Editar produto\n");
    printf("[4] - Excluir produto\n");
    printf("[5] - Procurar produto\n");
    printf("[6] - Sair\n");
    printf("===================================\n");    
    printf("Escolha uma opcao: ");
    int opcao = lerInteiro();

    return opcao;
}

int lerInteiro(){
    int numero = -1;

    do{
        fflush(stdin);
        if(scanf("%d", &numero) == 1 && numero >= 0){
            break;
        }
        printf("Insira um valor valido!\n");
    }while(1);

    return numero;
}

double lerDouble(){
    double numero = -1;

    do{
        fflush(stdin);
        if(scanf("%lf", &numero) == 1 && numero >= 0){
            break;
        }
        printf("Insira um valor valido!\n");
    }while(1);

    return numero;
}

char *lerString(){
    char *nome = (char *) malloc(75 * sizeof(char));
;
    bool valido = true;
    
    do{
        fflush(stdin);
        valido = true; 
        gets(nome);
        fflush(stdin);

        for(int i = 0; nome[i] != '\0'; i++){
            if(!(isalpha(nome[i]))){
                return false;
            }
        }
    }while(!valido);

    nomePadronizacao(nome);

    return nome;
}

void nomePadronizacao(char nome[]){
    int i;

    nome[0] = toupper(nome[0]);

    for(i=1; nome[i]!='\0'; i++){        
       nome[i] = tolower(nome[i]);
    }
}

void adicionarPro(){
    struct estoque produtos;
    FILE *pa;
    pa = fopen("estoque.dat", "ab");

    
    if(pa == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("ID: ");
    produtos.id = lerInteiro();


    printf("Nome: ");
    *produtos.nome = *lerString();

    printf("Quantidade: ");
    produtos.quantidade = lerInteiro();     

    printf("Preco: ");
    produtos.preco = lerDouble();

    fwrite(&produtos, sizeof(struct estoque), 1, pa);
    fclose(pa);

    printf("Produto adicionado com sucesso.\n");
}

void mostrarPro(){
    struct estoque produtos;
    FILE *pa;
    pa = fopen("estoque.dat", "rb");

    if(pa == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("\n===================================\n");
    while(fread(&produtos, sizeof(struct estoque), 1, pa)){
        printf("ID: %06d\tNome: %-20s\tPreco: $%-9.2f\tQuantidade: %06d\n", produtos.id, produtos.nome, produtos.preco, produtos.quantidade);
    }
    printf("===================================\n");

    fclose(pa);
}

void editarID(){
    struct estoque produtos;
    FILE *pa;
    pa = fopen("estoque.dat", "rb+");

    if(pa == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int id, existe=0;
    printf("Informe o ID: ");
    id = lerInteiro();

    while(fread(&produtos, sizeof(struct estoque), 1, pa)){
        if(produtos.id == id){
            printf("Informe o novo ID: ");
            produtos.id = lerInteiro();

            fseek(pa, -(long)sizeof(struct estoque), SEEK_CUR);
            fwrite(&produtos, sizeof(struct estoque), 1, pa);
            existe = 1;
            break;
        }
    }

    fclose(pa);

    if(!existe){
        printf("Erro ao encontrar o ID.\n");
    }else {
        printf("ID atualizado com sucesso!\n");
    }
}

void editarNome(){
    struct estoque produtos;
    FILE *pa;
    pa = fopen("estoque.dat", "rb+");

    if(pa == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int id, existe=0;
    printf("Informe o ID: ");
    id = lerInteiro();

    while(fread(&produtos, sizeof(struct estoque), 1, pa)){
        if(produtos.id == id){
            printf("Informe o novo nome: ");
            *produtos.nome = *lerString();

            fseek(pa, -(long)sizeof(struct estoque), SEEK_CUR);
            fwrite(&produtos, sizeof(struct estoque), 1, pa);
            existe = 1;
            break;
        }
    }

    fclose(pa);

    if(!existe){
        printf("Erro ao encontrar o ID.\n");
    }else {
        printf("Nome atualizado com sucesso!\n");
    }
}
    
void editarQuant(){
    int id, existe = 0;
    struct estoque produtos;
    FILE *pa;
    pa = fopen("estoque.dat", "rb+");

    if(pa == NULL){
        printf("Erro ao abrir o arquivo!");
        return;
    }

    printf("Informe o ID: ");
    id = lerInteiro();

    while(fread(&produtos, sizeof(struct estoque), 1, pa)){
        if(produtos.id == id){
            printf("Informe a nova quantidade: ");
            produtos.quantidade = lerInteiro();
            
            fseek(pa, -(long)sizeof(struct estoque), SEEK_CUR);
            fwrite(&produtos, sizeof(struct estoque), 1, pa);
            existe = 1;
            break;
        }
    }

    fclose(pa);

    if(!existe){
        printf("Erro ao encontrar o ID.\n");
    }else{
        printf("Id atualizado com sucesso!\n");
    }
}
    
void editarPreco(){
    int id, existe = 0;
    struct estoque produtos;
    FILE *pa;
    pa = fopen("estoque.dat", "rb+");

    if(pa == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Informe o iD: ");
    id = lerInteiro();

    while(fread(&produtos, sizeof(struct estoque), 1, pa)){
        if(produtos.id == id){
            printf("Informe o novo preco: ");
            produtos.preco = lerDouble();

            fseek(pa, -(long)sizeof(struct estoque), SEEK_CUR);
            fwrite(&produtos, sizeof(struct estoque), 1, pa);
            existe = 1;
            break;
        }
    }

    fclose(pa);

    if(!existe){
        printf("Produto nao encontrado.\n");
    }else {
        printf("Preco atualizado com sucesso!\n");
    }
}
    
void editarPro(){
    int opcao;

    printf("1 - Editar ID\n");
    printf("2 - Editar Nome\n");
    printf("3 - Editar Quantidade\n");
    printf("4 - Editar Preco\n");
    printf("Escolha uma opcao: ");
    opcao = lerInteiro();

    switch (opcao)
    {
        case 1:
            editarID();
            break;
        case 2:
            editarNome();
            break;
        case 3:
            editarQuant();
            break;
        case 4:
            editarPreco();
            break;
        
        default:
            printf("\nOpcao invalida!");
            return;
        }
    }

void excluirPro(){
    int id, existe = 0;
    struct estoque produtos;
    FILE *pa, *tem;
    pa = fopen("estoque.dat", "rb");

    if(pa == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    tem = fopen("temporario.dat", "wb");
    if(tem == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Informe o ID: ");
    id = lerInteiro();

    while(fread(&produtos, sizeof(struct estoque), 1, pa)){
        if(produtos.id != id){
            fwrite(&produtos, sizeof(struct estoque), 1, tem);
        }else{
            existe = 1;
        }
    }

    fclose(pa);
    fclose(tem);

    remove("estoque.dat");
    rename("temporario.dat", "estoque.dat");

    if(!existe){
        printf("Produto nao encontrado!\n");

    }else {
        printf("Produto excluido com sucesso!\n");
    }
}

void procurarPro(){
    int id, existe=0;
    struct estoque produtos;
    FILE *pa;
    pa = fopen("estoque.dat", "rb");

    if(pa == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    printf("Informe o ID: ");
    id = lerInteiro();
    while(fread(&produtos, sizeof(struct estoque), 1, pa)){
        if(produtos.id == id){
            printf("\n===================================\n");    
            printf("ID: %06d\tNome: %-20s\tPreco: $%-9.2f\tQuantidade: %06d\n", produtos.id, produtos.nome, produtos.preco, produtos.quantidade);
            printf("===================================\n");
            existe = 1;
            break;
        }
    }

    fclose(pa);

    if(!existe){
        printf("Produto nao encontrado!\n");
    }
}


void sair(){
    printf("Saindo do programa...");
    exit(0);
}