#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include <stdbool.h>

typedef struct lista_vertice
{
    char *nome;
    struct lista_vertice *next;
} lista_vertice;

typedef struct lista_grafo
{
    int tamanho;
    lista_vertice *vertice;
} lista_grafo;

lista_grafo *criar_lista(int tamanho);
void adicionar_vertice_lista(lista_grafo *grafo, int indice, char *nome);
void adicionar_aresta_lista(lista_grafo *grafo, int indice1, int indice2);
void remover_aresta_lista(lista_grafo *grafo, int indice1, int indice2);
bool isVizinho_lista(lista_grafo *grafo, int indice1, int indice2);
int calcular_grau_vertice(lista_grafo *grafo, int indice);
void imprimir_lista_vertices(lista_grafo *grafo);
void imprima_lista(lista_grafo *grafo);

#endif // ESTRUTURA_H
