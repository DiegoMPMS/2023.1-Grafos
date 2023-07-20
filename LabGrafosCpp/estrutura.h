#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include <stdbool.h>

typedef struct lista_vertice {
  char *nome;
  bool marcado;
  int profundidade_entrada;
  int profundidade_saida;
  struct lista_vertice *next;
} lista_vertice;

typedef struct lista_grafo {
  int tamanho;
  lista_vertice *vertice;
} lista_grafo;

lista_grafo *criar_lista(int tamanho);
void adicionar_vertice_lista(lista_grafo *grafo, int indice, char *nome);
void adicionar_aresta_lista(lista_grafo *grafo, int indice1, int indice2);
void adicionar_vertice_ordenado(lista_vertice *vertice, char *nome);
void remover_aresta_lista(lista_grafo *grafo, int indice1, int indice2);
bool isVizinho_lista(lista_grafo *grafo, int indice1, int indice2);
int calcular_grau_vertice(lista_grafo *grafo, int indice);
int buscar_vertice(lista_grafo *grafo, char *nome);
void busca_em_profundidade(lista_grafo *grafo, int indice);
void busca_em_profundidade_recursiva(lista_grafo *grafo, int indice);
void imprimir_lista_vertices(lista_grafo *grafo);
void imprimir_lista(lista_grafo *grafo);
void imprimir_profundidade(lista_grafo *grafo);
lista_grafo *subgrafo(lista_grafo *grafo, int *vertices, int tamanho_vertices,
                      int (*arestas)[2], int tamanho_arestas);
lista_grafo *subgrafo_induzido(lista_grafo *grafo, int *vertices, int tamanho);
lista_grafo *subtracao_vertices(lista_grafo *grafo, int *vertices, int tamanho);
lista_grafo *subgrafo_aresta_induzido(lista_grafo *grafo, int **arestas,
                                      int tamanho);
lista_grafo *subtracao_arestas(lista_grafo *grafo, int **arestas, int tamanho);

#endif  // ESTRUTURA_H
