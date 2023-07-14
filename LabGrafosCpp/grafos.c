#include "estrutura.h"
#include "matriz.h"

int main()
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

  adicionar_aresta_lista(listaGrafo, 0, 1); // (a,b)
  adicionar_aresta_lista(listaGrafo, 0, 2); // (a,c)
  adicionar_aresta_lista(listaGrafo, 0, 4); // (a,d)
  adicionar_aresta_lista(listaGrafo, 0, 5); // (a,f)
  adicionar_aresta_lista(listaGrafo, 1, 3); // (b,d)
  adicionar_aresta_lista(listaGrafo, 1, 4); // (b,e)
  adicionar_aresta_lista(listaGrafo, 2, 5); // (c,f)
  adicionar_aresta_lista(listaGrafo, 2, 6); // (c,g)
  adicionar_aresta_lista(listaGrafo, 2, 7); // (c,h)
  adicionar_aresta_lista(listaGrafo, 5, 6); // (f,g)
  adicionar_aresta_lista(listaGrafo, 5, 7); // (f,h)
  adicionar_aresta_lista(listaGrafo, 6, 7); // (g,h)

  imprima_lista(listaGrafo);

  return 0;
}