import GraphLib as Gl

# ---------- Parâmetros ---------- #
'''
Mude o valor de TEST_MODE para alternar entre os exercícios dos laboratórios
Lab 1 = 1; Lab 2 = 2; ... e assim por diante
'''
TEST_MODE = 1
test_param = 1  # essa variável serve apenas para o primeiro lab., ela define se o teste será feito
# com 1 Matriz de Adjacência ou 0 Estrutura de Adjacência


def grafo1():
    """
    Lab. 01 - Questão 1
    :return: 
    """
    G1 = Gl.grafo(test_param)
    for i in range(5):
        G1.add_vertice()
    G1.add_edge([(0, 1), (1, 2), (2, 2), (2, 3), (3, 1), (3, 4), (4, 1), (4, 1)])
    print('----------------')
    G1.print_g_all()


def grafo2():
    """
    Lab. 01 - Questão 2
    :return:
    """
    G2 = Gl.grafo(test_param)
    for i in range(5):
        G2.add_vertice()

    # Essa função cria Grafos completos de tamanho n_completo
    n_completo = 5
    for v1 in range(n_completo):
        for v2 in range(n_completo):
            if v1 != v2 and v2 > v1:
                G2.add_edge([(v1, v2)])
    print('----------------')
    G2.print_g_all()


if __name__ == '__main__':

    match TEST_MODE:
        case 1:
            '''Lab 01 - Exercício 1.8 '''
            grafo1()
            grafo2()
        case 2:
            '''Lab 02 - Exercício '''
            G3 = Gl.create_complete(7)
            G3.print_g_all()

            G4 = Gl.create_k_regular(6, 1)
            G4.print_g_all()


