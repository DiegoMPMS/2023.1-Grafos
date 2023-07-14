#include "matriz.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

matriz_grafo *criar_matriz(int tamanho)
{
  matriz_grafo *grafo = malloc(sizeof(matriz_grafo));
  grafo->vertice = malloc(tamanho * sizeof(matriz_vertice));
  grafo->matriz = malloc(tamanho * sizeof(int *));
  grafo->tamanho_total = tamanho;

  for (int i = 0; i < tamanho; i++)
  {
    grafo->matriz[i] = calloc(tamanho, sizeof(int));
    grafo->vertice[i].criado = 0;
    grafo->vertice[i].grau = 0;
  }

  return grafo;
}

void adicionar_vertice_matriz(matriz_grafo *grafo, int indice, const char *nome)
{
  free(grafo->vertice[indice].nome);
  grafo->vertice[indice].nome = strdup(nome);
  grafo->vertice[indice].criado = 1;
  grafo->vertice[indice].grau = 0;
}

void adicionar_aresta_matriz(matriz_grafo *grafo, int vertice1, int vertice2)
{
  if (grafo->vertice[vertice1].criado && grafo->vertice[vertice2].criado)
  {
    if (vertice1 == vertice2)
    {
      grafo->matriz[vertice1][vertice2] += 2;
      grafo->vertice[vertice1].grau += 2;
    }
    else
    {
      grafo->matriz[vertice1][vertice2] += 1;
      grafo->matriz[vertice2][vertice1] += 1;
      grafo->vertice[vertice1].grau += 1;
      grafo->vertice[vertice2].grau += 1;
    }
  }
}

void remover_aresta_matriz(matriz_grafo *grafo, int vertice1, int vertice2)
{
  if (grafo->vertice[vertice1].criado && grafo->vertice[vertice2].criado)
  {
    if (vertice1 == vertice2 && grafo->vertice[vertice1].grau > 0)
    {
      grafo->matriz[vertice1][vertice2] -= 2;
      grafo->matriz[vertice2][vertice1] -= 2;
      grafo->vertice[vertice1].grau -= 2;
    }
    else if (grafo->vertice[vertice1].grau > 0 && grafo->vertice[vertice2].grau > 0)
    {
      grafo->matriz[vertice1][vertice2] -= 1;
      grafo->matriz[vertice2][vertice1] -= 1;
      grafo->vertice[vertice1].grau -= 1;
      grafo->vertice[vertice2].grau -= 1;
    }
  }
}

bool isVizinho_matriz(matriz_grafo *grafo, int vertice1, int vertice2)
{
  return grafo->matriz[vertice1][vertice2] > 0 && grafo->matriz[vertice2][vertice1] > 0 &&
         grafo->matriz[vertice2][vertice1] == grafo->matriz[vertice1][vertice2];
}

void imprima_matriz(matriz_grafo *grafo)
{
  printf("== Grafo em matriz\n");

  int num_vertices = 0;
  for (int i = 0; i < grafo->tamanho_total; i++)
  {
    if (grafo->vertice[i].criado)
    {
      num_vertices++;
    }
  }

  printf("numero de vertices: %d\n", num_vertices);
  int total_arestas = 0;
  for (int i = 0; i < grafo->tamanho_total; i++)
  {
    for (int j = 0; j < grafo->tamanho_total; j++)
    {
      total_arestas += grafo->matriz[i][j];
    }
  }
  total_arestas = total_arestas / 2;
  printf("Numero de arestas: %d\n", total_arestas);
  for (int i = 0; i < grafo->tamanho_total; i++)
  {
    if (grafo->vertice[i].criado)
    {
      printf("Nome do vertice %d: %s,  grau: %d\n", i + 1, grafo->vertice[i].nome, grafo->vertice[i].grau);
    }
  }
  printf("grafo em forma de matriz:\n");
  printf("%-5s", "");
  for (int i = 0; i < grafo->tamanho_total; i++)
  {
    printf("%-5s", grafo->vertice[i].nome);
  }
  printf("\n");
  for (int i = 0; i < grafo->tamanho_total; i++)
  {
    printf("%-5s", grafo->vertice[i].nome);
    for (int j = 0; j < grafo->tamanho_total; j++)
    {
      printf("%-5d", grafo->matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}