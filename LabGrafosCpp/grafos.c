// Grafo de matriz:
// exercicio 1.1: ok!
// exercicio 1.2: ok!
// exercicio 1.3: ok!
// exercicio 1.4: ok!
// exercicio 1.5: ok!
// exercicio 1.6: ok!
// exercicio 1.7: ok!
// exercicio 1.8: ok!

// Grafo de estrutura:
// exercicio 1.1: ok!
// exercicio 1.2: ok!
// exercicio 1.3: ok!
// exercicio 1.4: ok!
// exercicio 1.5: ok!
// exercicio 1.6: ok!
// exercicio 1.7: ok!
// exercicio 1.8: ok!

// ? é preciso desenhar os dois grafos da qs 1.8 da matriz e lista?
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Matriz
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

// Matriz
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

// Estrutura de dados
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

int main()
{
  // matriz grafo 1
  matriz_grafo *matrizGrafo = criar_matriz(5);

  adicionar_vertice_matriz(matrizGrafo, 0, "v1");
  adicionar_vertice_matriz(matrizGrafo, 1, "v2");
  adicionar_vertice_matriz(matrizGrafo, 2, "v3");
  adicionar_vertice_matriz(matrizGrafo, 3, "v4");
  adicionar_vertice_matriz(matrizGrafo, 4, "v5");

  adicionar_aresta_matriz(matrizGrafo, 0, 1);
  adicionar_aresta_matriz(matrizGrafo, 1, 2);
  adicionar_aresta_matriz(matrizGrafo, 1, 3);
  adicionar_aresta_matriz(matrizGrafo, 1, 4);
  adicionar_aresta_matriz(matrizGrafo, 1, 4);
  adicionar_aresta_matriz(matrizGrafo, 2, 2);
  adicionar_aresta_matriz(matrizGrafo, 2, 3);
  adicionar_aresta_matriz(matrizGrafo, 3, 4);

  // remover_aresta_matriz(matriz_grafo, 0, 1);
  // printf("é vizinho? %d", isVizinho_matriz(matrizGrafo, 0, 1));

  imprima_matriz(matrizGrafo);

  // estrutura de grafo 2 (pentagrama)
  lista_grafo *listaGrafo = criar_lista(5);

  adicionar_vertice_lista(listaGrafo, 0, "v1");
  adicionar_vertice_lista(listaGrafo, 1, "v2");
  adicionar_vertice_lista(listaGrafo, 2, "v3");
  adicionar_vertice_lista(listaGrafo, 3, "v4");
  adicionar_vertice_lista(listaGrafo, 4, "v5");

  adicionar_aresta_lista(listaGrafo, 0, 1);
  adicionar_aresta_lista(listaGrafo, 0, 2);
  adicionar_aresta_lista(listaGrafo, 0, 3);
  adicionar_aresta_lista(listaGrafo, 0, 4);
  adicionar_aresta_lista(listaGrafo, 1, 2);
  adicionar_aresta_lista(listaGrafo, 1, 3);
  adicionar_aresta_lista(listaGrafo, 1, 4);
  adicionar_aresta_lista(listaGrafo, 2, 3);
  adicionar_aresta_lista(listaGrafo, 2, 4);
  adicionar_aresta_lista(listaGrafo, 3, 4);

  // isVizinho_lista(listaGrafo, 0, 0);
  // remover_aresta_lista(listaGrafo, 0, 1);
  // imprimir_lista_vertices(listaGrafo);
  
  imprima_lista(listaGrafo);
  return 0;
}