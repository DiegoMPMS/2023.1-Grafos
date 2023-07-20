#include "estrutura.h"
#include "matriz.h"

void exercicio1()
{
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

  imprimir_matriz(matrizGrafo);
  free(matrizGrafo);
}

void exercicio3()
{
  lista_grafo *listaGrafo = criar_lista(8);

  adicionar_vertice_lista(listaGrafo, 0, "a");
  adicionar_vertice_lista(listaGrafo, 1, "b");
  adicionar_vertice_lista(listaGrafo, 2, "c");
  adicionar_vertice_lista(listaGrafo, 3, "d");
  adicionar_vertice_lista(listaGrafo, 4, "e");
  adicionar_vertice_lista(listaGrafo, 5, "f");
  adicionar_vertice_lista(listaGrafo, 6, "g");
  adicionar_vertice_lista(listaGrafo, 7, "h");

  adicionar_aresta_lista(listaGrafo, 0, 5); // (a,f)
  adicionar_aresta_lista(listaGrafo, 0, 4); // (a,e)
  adicionar_aresta_lista(listaGrafo, 0, 2); // (a,c)
  adicionar_aresta_lista(listaGrafo, 1, 4); // (b,e)
  adicionar_aresta_lista(listaGrafo, 1, 3); // (b,d)
  adicionar_aresta_lista(listaGrafo, 0, 1); // (a,b)
  adicionar_aresta_lista(listaGrafo, 2, 5); // (c,f)
  adicionar_aresta_lista(listaGrafo, 2, 6); // (c,g)
  adicionar_aresta_lista(listaGrafo, 2, 7); // (c,h)
  adicionar_aresta_lista(listaGrafo, 5, 6); // (f,g)
  adicionar_aresta_lista(listaGrafo, 6, 7); // (g,h)
  adicionar_aresta_lista(listaGrafo, 5, 7); // (f,h)
  adicionar_aresta_lista(listaGrafo, 7, 5); // (f,h)

  imprimir_lista(listaGrafo);

  // busca em profundidade
  busca_em_profundidade(listaGrafo, 0);
  imprimir_profundidade(listaGrafo);

  free(listaGrafo);
}

void exercicio4() {
  lista_grafo *G = criar_lista(5);
  adicionar_vertice_lista(G, 0, "u");
  adicionar_vertice_lista(G, 1, "y");
  adicionar_vertice_lista(G, 2, "x");
  adicionar_vertice_lista(G, 3, "w");
  adicionar_vertice_lista(G, 4, "v");

  adicionar_aresta_lista(G, 0, 1);  // (u,y)
  adicionar_aresta_lista(G, 0, 4);  // (u,v)
  adicionar_aresta_lista(G, 4, 3);  // (v,w)
  adicionar_aresta_lista(G, 4, 1);  // (v,y)
  adicionar_aresta_lista(G, 4, 1);  // (v,y)
  adicionar_aresta_lista(G, 3, 1);  // (w,y)
  adicionar_aresta_lista(G, 1, 2);  // (y,x)
  adicionar_aresta_lista(G, 2, 3);  // (x,w)

  imprimir_lista(G);

  // int vertices_subgrafo[] = {0, 1, 2};
  // int size_vertices_subgrafo = sizeof(vertices_subgrafo) /
  // sizeof(vertices_subgrafo[0]); int arestas_subgrafo[][2] = {{0, 1}, {0, 2},
  // {2, 1}}; int size_arestras_subgrafo = sizeof(arestas_subgrafo) /
  // sizeof(arestas_subgrafo[0]); lista_grafo *subgrafo_gerador = subgrafo(G,
  // vertices_subgrafo, size_vertices_subgrafo, arestas_subgrafo,
  // size_arestras_subgrafo); imprimir_lista(subgrafo_gerador);

  int X1[] = {1, 4, 2, 0};
  int size_X1 = sizeof(X1) / sizeof(X1[0]);
  lista_grafo *grafo_X1 = subgrafo_induzido(G, X1, size_X1);
  imprimir_lista(grafo_X1);

  int X2[] = {0, 3};
  int size_X2 = sizeof(X2) / sizeof(X2[0]);
  lista_grafo *grafo_X2 = subtracao_vertices(G, X2, size_X2);
  imprimir_lista(grafo_X2);
}

int main()
{
  exercicio4();
  return 0;
}