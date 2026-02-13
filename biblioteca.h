#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct estoque Estoque;

int lerInteiro();
double lerDouble();
char *lerString();
void nomePadronizacao(char nome[]);

int opcoes();
void adicionarPro();
void mostrarPro();
void editarPro();
void procurarPro();
void excluirPro();
void sair();

void editarID();
void editarNome();
void editarQuant();
void editarPreco();