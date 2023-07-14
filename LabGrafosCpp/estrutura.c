#include "estrutura.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

lista_grafo *criar_lista(int tamanho)
{
  lista_grafo *grafo = malloc(sizeof(lista_grafo));
  grafo->vertice = malloc(tamanho * sizeof(lista_vertice));
  grafo->tamanho = tamanho;

  for (int i = 0; i < tamanho; i++)
  {
    grafo->vertice[i].nome = NULL;
    grafo->vertice[i].next = NULL;
  }

  return grafo;
}

void adicionar_vertice_lista(lista_grafo *grafo, int indice, char *nome)
{

  grafo->vertice[indice].nome = strdup(nome);
}

void adicionar_aresta_lista(lista_grafo *grafo, int indice1, int indice2)
{
  lista_vertice *vertice1 = &(grafo->vertice[indice1]);
  lista_vertice *vertice2 = &(grafo->vertice[indice2]);

  lista_vertice *novo_vertice1 = (lista_vertice *)malloc(sizeof(lista_vertice));
  novo_vertice1->nome = vertice2->nome;
  novo_vertice1->next = vertice1->next;

  vertice1->next = novo_vertice1;

  lista_vertice *novo_vertice2 = (lista_vertice *)malloc(sizeof(lista_vertice));
  novo_vertice2->nome = vertice1->nome;
  novo_vertice2->next = vertice2->next;
  vertice2->next = novo_vertice2;
}

void remover_aresta_lista(lista_grafo *grafo, int indice1, int indice2)
{
  lista_vertice *vertice1 = &(grafo->vertice[indice1]);

  // Verificação se a aresta a ser removida é a primeira
  if (vertice1->next != NULL && vertice1->next->nome == grafo->vertice[indice2].nome)
  {
    lista_vertice *temp = vertice1->next;
    vertice1->next = temp->next;
    free(temp);
  }
  else
  {
    lista_vertice *current = vertice1->next;
    lista_vertice *prev = vertice1;

    // Percorre a lista de vizinhos do vértice1 para encontrar a aresta a ser removida
    while (current != NULL && current->nome != grafo->vertice[indice2].nome)
    {
      prev = current;
      current = current->next;
    }

    // Se encontrou a aresta, remove-a
    if (current != NULL)
    {
      prev->next = current->next;
      free(current);
    }
  }
}

bool isVizinho_lista(lista_grafo *grafo, int indice1, int indice2)
{
  lista_vertice *vertice1 = &(grafo->vertice[indice1]);

  lista_vertice *current = vertice1->next;
  while (current != NULL)
  {
    if (strcmp(current->nome, grafo->vertice[indice2].nome) == 0)
    {
      return true;
    }
    current = current->next;
  }

  return false;
}

int calcular_grau_vertice(lista_grafo *grafo, int indice)
{
  int grau = 0;
  lista_vertice *vertice = &(grafo->vertice[indice]);

  lista_vertice *vizinho = vertice->next;
  while (vizinho != NULL)
  {
    grau++;
    vizinho = vizinho->next;
  }

  return grau;
}

void imprimir_lista_vertices(lista_grafo *grafo)
{
  for (int i = 0; i < grafo->tamanho; i++)
  {
    lista_vertice *current = &(grafo->vertice[i]);
    printf("Vértice %s: ", current->nome);
    current = current->next;
    while (current != NULL)
    {
      printf("%s ", current->nome);
      current = current->next;
    }

    printf("\n");
  }
}

void imprima_lista(lista_grafo *grafo)
{
  printf("== Grafo em lista encadeada\n");
  int numvertices = 0;
  for (int i = 0; i < grafo->tamanho; i++)
  {
    if (grafo->vertice[i].nome != NULL)
    {
      numvertices += 1;
    }
  }
  printf("Numero de vertices:%d\n", numvertices);

  int num_grau_vertices = 0;
  for (int i = 0; i < grafo->tamanho; i++)
  {
    if (grafo->vertice[i].nome != NULL)
    {
      num_grau_vertices += calcular_grau_vertice(grafo, i);
    }
  }

  printf("Numero de arestas: %d\n", num_grau_vertices / 2);
  for (int i = 0; i < grafo->tamanho; i++)
  {
    if (grafo->vertice[i].nome != NULL)
    {
      printf("Nome do vertice %d: %s,  grau: %d\n", i + 1, grafo->vertice[i].nome, calcular_grau_vertice(grafo, i));
    }
  }

  printf("Lista de adjacencia\n");
  imprimir_lista_vertices(grafo);
}