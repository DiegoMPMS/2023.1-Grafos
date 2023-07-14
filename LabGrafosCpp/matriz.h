#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct matriz_vertice
{
  char *nome;
  int criado;
  int grau;
} matriz_vertice;

typedef struct matriz_grafo
{
  int tamanho_total;
  matriz_vertice *vertice;
  int **matriz;
} matriz_grafo;

matriz_grafo* criar_matriz(int tamanho);
void adicionar_vertice_matriz(matriz_grafo* grafo, int indice, const char* nome);
void adicionar_aresta_matriz(matriz_grafo* grafo, int vertice1, int vertice2);
void remover_aresta_matriz(matriz_grafo* grafo, int vertice1, int vertice2);
bool isVizinho_matriz(matriz_grafo* grafo, int vertice1, int vertice2);
void imprima_matriz(matriz_grafo* grafo);

#endif // MATRIZ_H
