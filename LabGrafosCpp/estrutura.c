
#include "estrutura.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int contador_entrada = 0;
static int contador_saida = 0;

lista_grafo *criar_lista(int tamanho) {
  // Alocar memória para a estrutura lista_grafo
  lista_grafo *grafo = malloc(sizeof(lista_grafo));
  grafo->vertice = malloc(tamanho * sizeof(lista_vertice));
  // Definir tamanho do grafo
  grafo->tamanho = tamanho;
  // Inicializar os vértices
  for (int i = 0; i < tamanho; i++) {
    // Definir o nome como NULL, profundidades como 0, marcado como falso e
    // próximo como NULL
    grafo->vertice[i].nome = NULL;
    grafo->vertice[i].profundidade_entrada = 0;
    grafo->vertice[i].profundidade_saida = 0;
    grafo->vertice[i].marcado = false;
    grafo->vertice[i].next = NULL;
  }

  return grafo;
}

void adicionar_vertice_lista(lista_grafo *grafo, int indice, char *nome) {
  // Atribuir o nome ao vértice no índice especificado
  grafo->vertice[indice].nome = strdup(nome);
}

void adicionar_aresta_lista(lista_grafo *grafo, int indice1, int indice2) {
  // Verificar se a aresta já existe
  // if (isVizinho_lista(grafo, indice1, indice2)) return;

  // Obter os ponteiros para os vértices a serem conectados
  lista_vertice *vertice1 = &(grafo->vertice[indice1]);
  lista_vertice *vertice2 = &(grafo->vertice[indice2]);

  // Adicionar os vértices como vizinhos um do outro
  adicionar_vertice_ordenado(vertice1, vertice2->nome);
  adicionar_vertice_ordenado(vertice2, vertice1->nome);
}

void adicionar_vertice_ordenado(lista_vertice *vertice, char *nome) {
  // Criar novo vértice
  lista_vertice *novo_vertice = (lista_vertice *)malloc(sizeof(lista_vertice));
  novo_vertice->nome = strdup(nome);
  novo_vertice->next = NULL;

  // Encontrar a posição correta na lista de vizinhos ordenados
  lista_vertice *atual = vertice;
  lista_vertice *anterior = NULL;
  while (atual != NULL && strcmp(atual->nome, nome) < 0) {
    anterior = atual;
    atual = atual->next;
  }

  // Inserir o novo vértice na posição correta
  if (anterior == NULL) {
    // O novo vértice será o primeiro da lista
    novo_vertice->next = vertice->next;
    vertice->next = novo_vertice;
  } else {
    // O novo vértice será inserido entre o anterior e o atual
    novo_vertice->next = anterior->next;
    anterior->next = novo_vertice;
  }
}

void remover_aresta_lista(lista_grafo *grafo, int indice1, int indice2) {
  char *nome1 = strdup(grafo->vertice[indice1].nome);
  char *nome2 = strdup(grafo->vertice[indice2].nome);

  lista_vertice *vertice1 = &(grafo->vertice[indice1]);
  lista_vertice *vertice2 = &(grafo->vertice[indice2]);
  remover_vertice(vertice1, nome2);
  remover_vertice(vertice2, nome1);
}

void remover_vertice(lista_vertice *vertice1, char *nome) {
  lista_vertice *current = vertice1;
  lista_vertice *prev = NULL;
  current = current->next;

  while (current != NULL && strcmp(current->nome, nome) != 0) {
    prev = current;
    current = current->next;
  }

  if (current == NULL) return;

  if (prev == NULL) {
    vertice1->next = current->next;
  } else {
    prev->next = current->next;
  }

  free(current);
}
bool isVizinho_lista(lista_grafo *grafo, int indice1, int indice2) {
  // Obtém o ponteiro para o vértice1 no índice1
  lista_vertice *vertice1 = &(grafo->vertice[indice1]);

  // Inicializa o ponteiro para percorrer a lista de vizinhos do vértice1
  lista_vertice *current = vertice1->next;

  // Percorre a lista de vizinhos do vértice1
  while (current != NULL) {
    // Verifica se o nome do vértice atual é igual ao nome do vértice2
    if (strcmp(current->nome, grafo->vertice[indice2].nome) == 0) {
      // Se encontrou uma correspondência, retorna verdadeiro
      return true;
    }

    // Avança para o próximo vértice na lista de vizinhos
    current = current->next;
  }

  // Se não encontrou uma correspondência, retorna falso
  return false;
}

int calcular_grau_vertice(lista_grafo *grafo, int indice) {
  // Inicializa a variável para armazenar o grau do vértice
  int grau = 0;

  // Obtém o ponteiro para o vértice no índice especificado
  lista_vertice *vertice = &(grafo->vertice[indice]);

  // Inicializa o ponteiro para percorrer a lista de vizinhos do vértice
  lista_vertice *vizinho = vertice->next;

  // Percorre a lista de vizinhos do vértice
  while (vizinho != NULL) {
    // Incrementa o grau do vértice
    grau++;

    // Avança para o próximo vértice na lista de vizinhos
    vizinho = vizinho->next;
  }

  // Retorna o grau do vértice
  return grau;
}

int buscar_indice_vertice(lista_grafo *grafo, char *nome) {
  // Percorre os vértices do grafo
  for (int i = 0; i < grafo->tamanho; i++) {
    // Verifica se o vértice no índice i possui um nome válido e se o nome
    // corresponde ao nome buscado
    if (grafo->vertice[i].nome != NULL &&
        strcmp(grafo->vertice[i].nome, nome) == 0)
      return i;  // Retorna o índice do vértice encontrado
  }

  return -1;  // Retorna -1 se o vértice não foi encontrado
}

void buscar_em_profundidade(lista_grafo *grafo, int indice) {
  contador_entrada = 1;
  contador_saida = 1;

  // Percorre os vértices do grafo
  for (int i = 0; i < grafo->tamanho; i++) {
    // Verifica se o vértice no índice i possui um nome válido e se o nome
    // corresponde ao nome buscado
    if (grafo->vertice[i].nome != NULL) {
      grafo->vertice[i].marcado = false;
      grafo->vertice[i].profundidade_entrada = 0;
      grafo->vertice[i].profundidade_saida = 0;
    }
  }

  busca_em_profundidade_recursiva(grafo, indice);
}

void buscar_em_profundidade_recursiva(lista_grafo *grafo, int indice) {
  // Obtém o ponteiro para o vértice de índice fornecido
  lista_vertice *current = &(grafo->vertice[indice]);

  // Marca o vértice como visitado
  current->marcado = true;
  current->profundidade_entrada = contador_entrada;
  contador_entrada++;

  // Imprime uma mensagem indicando que o vértice foi visitado
  printf("Vértice %s visitado\n", current->nome);

  // Percorre os vizinhos do vértice atual
  while (current->next != NULL) {
    // Obtém o índice do próximo vértice a ser visitado
    int tmp_indice = buscar_indice_vertice(grafo, current->next->nome);

    // Verifica se o vértice ainda não foi visitado
    if (!grafo->vertice[tmp_indice].marcado) {
      // Realiza a busca em profundidade recursivamente a partir do vértice não
      // visitado
      busca_em_profundidade_recursiva(grafo, tmp_indice);
    }

    // Avança para o próximo vértice na lista de vizinhos
    current = current->next;
  }

  grafo->vertice[indice].profundidade_saida = contador_saida;
  printf("Vértice %s saiu\n", grafo->vertice[indice].nome);  // DEBUG
  contador_saida++;
}

void imprimir_lista_vertices(lista_grafo *grafo) {
  for (int i = 0; i < grafo->tamanho; i++) {
    lista_vertice *current = &(grafo->vertice[i]);
    printf("Vértice %s: ", current->nome);
    current = current->next;
    while (current != NULL) {
      printf("%s ", current->nome);
      current = current->next;
    }

    printf("\n");
  }
}

void imprimir_lista(lista_grafo *grafo) {
  printf("\n=== Grafo em lista encadeada\n");
  int numvertices = 0;
  for (int i = 0; i < grafo->tamanho; i++) {
    if (grafo->vertice[i].nome != NULL) {
      numvertices += 1;
    }
  }
  printf("Numero de vertices: %d\n", numvertices);

  int num_grau_vertices = 0;
  for (int i = 0; i < grafo->tamanho; i++) {
    if (grafo->vertice[i].nome != NULL) {
      num_grau_vertices += calcular_grau_vertice(grafo, i);
    }
  }

  printf("Numero de arestas: %d\n", num_grau_vertices / 2);
  for (int i = 0; i < grafo->tamanho; i++) {
    if (grafo->vertice[i].nome != NULL) {
      printf("Nome do vertice %d: %s,  grau: %d\n", i + 1,
             grafo->vertice[i].nome, calcular_grau_vertice(grafo, i));
    }
  }

  printf("= Lista de adjacencia\n");
  imprimir_lista_vertices(grafo);
}

void imprimir_profundidade(lista_grafo *grafo) {
  printf("== Busca em profundidade\n");
  for (int i = 0; i < grafo->tamanho; i++) {
    if (grafo->vertice[i].nome != NULL) {
      printf(
          "Nome do vertice %d: %s,  profundidade entrada: %d, profundidade "
          "saida: %d\n",
          i + 1, grafo->vertice[i].nome, grafo->vertice[i].profundidade_entrada,
          grafo->vertice[i].profundidade_saida);
    }
  }
}

lista_grafo *subgrafo(lista_grafo *grafo, int *vertices, int tamanho_vertices,
                      int (*arestas)[2], int tamanho_arestas) {
  // Criar um novo grafo
  lista_grafo *subgrafo = criar_lista(tamanho_vertices);

  // Adicionar os vértices do subgrafo
  for (int i = 0; i < tamanho_vertices; i++) {
    adicionar_vertice_lista(subgrafo, i, grafo->vertice[vertices[i]].nome);
  }

  // Adicionar as arestas do subgrafo
  for (int i = 0; i < tamanho_arestas; i++) {
    adicionar_aresta_lista(subgrafo, arestas[i][0], arestas[i][1]);
  }

  return subgrafo;
}

lista_grafo *subgrafo_induzido(lista_grafo *grafo, int *vertices,
                               int subgrafo_tamanho) {
  // Criar um novo grafo
  lista_grafo *subgrafo = criar_lista(subgrafo_tamanho);

  // Adicionar os vértices do subgrafo
  for (int i = 0; i < subgrafo_tamanho; i++) {
    adicionar_vertice_lista(subgrafo, i, grafo->vertice[vertices[i]].nome);
  }

  // Adicionar as arestas do subgrafo
  for (int i = 0; i < subgrafo_tamanho; i++) {
    for (int j = i + 1; j < subgrafo_tamanho; j++) {
      if (isVizinho_lista(grafo, vertices[i], vertices[j])) {
        adicionar_aresta_lista(subgrafo, i, j);
      }
    }
  }

  return subgrafo;
}

lista_grafo *subtracao_vertices(lista_grafo *grafo, int *vertices,
                                int novo_tamanho) {
  // criar um novo grafo
  lista_grafo *subgrafo = criar_lista(grafo->tamanho - novo_tamanho);

  // Procura os vértices que não estão no subgrafo e adiciona em conjunto com
  // suas respectivas arestas
  char **nomes = malloc(novo_tamanho * sizeof(char *));
  for (int i = 0; i < novo_tamanho; i++) {
    nomes[i] = grafo->vertice[vertices[i]].nome;
  }

  int size_used = 0;
  for (int i = 0; i < grafo->tamanho; i++) {
    bool grafo_vertice_encontrado = false;
    for (int j = 0; j < novo_tamanho; j++) {
      if (strcmp(grafo->vertice[i].nome, nomes[j]) == 0) {
        grafo_vertice_encontrado = true;
        break;
      }
    }

    if (!grafo_vertice_encontrado) {
      adicionar_vertice_lista(subgrafo, size_used, grafo->vertice[i].nome);

      lista_vertice *current = &(grafo->vertice[i]);
      lista_vertice *current_aux = &(subgrafo->vertice[size_used++]);
      current = current->next;
      while (current != NULL) {
        bool grafo_vertice_encontrado_nas_arestas = false;

        for (int j = 0; j < novo_tamanho; j++) {
          if (strcmp(current->nome, nomes[j]) == 0) {
            grafo_vertice_encontrado_nas_arestas = true;
            break;
          }
        }
        if (!grafo_vertice_encontrado_nas_arestas) {
          adicionar_vertice_ordenado(current_aux, current->nome);
        }
        current = current->next;
      }
    }
  }

  return subgrafo;
}

bool isDuplicate(int *uniqueArr, int size, int element) {
  for (int i = 0; i < size; i++) {
    if (uniqueArr[i] == element) return true;
  }
  return false;
}

int *create_set_vertices(int (*arestas)[2], int size_arestas, int *size) {
  int *set_vertices = malloc(2 * size_arestas * sizeof(int));
  int size_set_vertices = 0;

  // Procura por duplicados e adiciona apenas os únicos elementos no array
  for (int i = 0; i < size_arestas; i++) {
    int vertice1 = arestas[i][0];
    int vertice2 = arestas[i][1];
    bool duplicate1 = isDuplicate(set_vertices, size_set_vertices, vertice1);
    bool duplicate2 = isDuplicate(set_vertices, size_set_vertices, vertice2);

    if (!duplicate1) {
      set_vertices[size_set_vertices] = vertice1;
      size_set_vertices++;
    }

    if (vertice1 != vertice2 && !duplicate2) {
      set_vertices[size_set_vertices] = vertice2;
      size_set_vertices++;
    }
  }

  *(size) = size_set_vertices;
  return set_vertices;
}

lista_grafo *subgrafo_aresta_induzido(lista_grafo *grafo, int (*arestas)[2],
                                      int subgrafo_tamanho) {
  // Criar uma lista de quais vertices adicionar no novo subgrafo
  int size_set_vertices;
  int *set_vertices =
      create_set_vertices(arestas, subgrafo_tamanho, &size_set_vertices);

  // Criar um novo grafo
  lista_grafo *subgrafo = criar_lista(size_set_vertices);

  // Adicionar os vértices do subgrafo
  for (int i = 0; i < size_set_vertices; i++) {
    adicionar_vertice_lista(subgrafo, i, grafo->vertice[set_vertices[i]].nome);
  }

  // Adicionar as arestas do subgrafo
  for (int i = 0; i < subgrafo_tamanho; i++) {
    int vertice1 = arestas[i][0];
    int vertice2 = arestas[i][1];
    int indice_vertice1 =
        buscar_indice_vertice(grafo, grafo->vertice[vertice1].nome);
    int indice_vertice2 =
        buscar_indice_vertice(grafo, grafo->vertice[vertice2].nome);

    adicionar_aresta_lista(subgrafo, indice_vertice1, indice_vertice2);
  }

  free(set_vertices);
  return subgrafo;
}

lista_grafo *copiar_grafo(lista_grafo *grafo) {
  // copiar o grafo
  lista_grafo *subgrafo = criar_lista(grafo->tamanho);

  for (int i = 0; i < grafo->tamanho; i++) {
    adicionar_vertice_lista(subgrafo, i, grafo->vertice[i].nome);
    lista_vertice *current = &(grafo->vertice[i]);
    lista_vertice *current_subgrafo = &(subgrafo->vertice[i]);
    current = current->next;
    while (current != NULL) {
      adicionar_vertice_ordenado(current_subgrafo, current->nome);
      current = current->next;
    }
  }

  return subgrafo;
}

lista_grafo *subtracao_arestas(lista_grafo *grafo, int (*arestas)[2],
                               int subgrafo_tamanho) {
  // Criar um novo grafo
  lista_grafo *subgrafo = copiar_grafo(grafo);

  for (int i = 0; i < subgrafo_tamanho; i++) {
    remover_aresta_lista(subgrafo, arestas[i][0], arestas[i][1]);
  }

  return subgrafo;
}
