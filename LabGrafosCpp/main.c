#include "estrutura.h"
#include "matriz.h"

void testarMatriz()
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

  imprima_matriz(matrizGrafo);
  free(matrizGrafo);
}

void testarEstrutura()
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

  imprima_lista(listaGrafo);
  
  // busca em profundidade
  busca_em_profundidade(listaGrafo, 0);
  imprima_profundidade(listaGrafo);

  free(listaGrafo);
}

int main()
{
  testarEstrutura();

  return 0;
}