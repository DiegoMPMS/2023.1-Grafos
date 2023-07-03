# Grafos serão representados por:
# Matrizes de adjacência utilizando numpy
# Estruturas de adjacência utilizando Dicionários
'''
Pacotes Necessários: numpy
Estruturas / Classes:
    vertex (vértice)
    edge (aresta)
    grafo
Métodos:
    create_complete(n) : cria grafo completo de grau 'n'
    create_k_regular(n, k) : cria grafo 'k' regular com 'n' vértices
'''
import numpy as np


class vertex:
    def __init__(self, id_v):
        self.id_v = id_v


class edge:
    def __init__(self, id_e, par):
        self.id_e = id_e
        self.par = par


class grafo:
    def __init__(self, tipo=0):
        # tipo 0 = Estrutura, 1 = Matriz.
        self.tipo = tipo
        self.v_id_count = 0
        self.e_id_count = 0
        match tipo:
            case 0:
                self.v_list = []
                self.e_list = []
                self.struct0 = {}
            case 1:
                self.v_list = []
                self.e_list = []
                self.struct1 = np.empty(shape=(0, 0), dtype=int)
            case _:
                print('Tipo Invalido de estrutura \n',
                      'Utilize as poções: \n',
                      '0 -> Estrutura de Adjacência \n',
                      '1 -> Matriz de Adjacência')
                raise Exception()

    def print_g(self):
        if self.tipo:
            print(self.struct1)
        else:
            print(self.struct0)

    def print_g_all(self):
        if self.tipo:
            print('----- Info -----')
            print('Número de Vértices: ', len(self.v_list))
            print('Número de Arestas:', len(self.e_list))
            print('----- Grafo -----')
            print(self.struct1)
            print('----- Vertices e Grau -----')
            v_l_print = {}
            for v in self.v_list:
                v_l_print[v.id_v] = self.get_grau(v.id_v)
            print(v_l_print)
            print('----- Arestas -----')
            e_l_print = []
            for e in self.e_list:
                e_l_print.append(e.par)
            print(e_l_print)
        else:
            print('----- Info -----')
            print('Número de Vértices: ', len(self.v_list))
            print('Número de Arestas:', len(self.e_list))
            print('----- Grafo -----')
            print(self.struct0)
            print('----- Vertices e Grau-----')
            v_l_print = {}
            for v in self.v_list:
                v_l_print[v.id_v] = self.get_grau(v.id_v)
            print(v_l_print)
            print('----- Arestas -----')
            e_l_print = []
            for e in self.e_list:
                e_l_print.append(e.par)
            print(e_l_print)

    def is_vizinho(self, a: int, b: int):
        match self.tipo:
            case 0:
                if a in self.struct0 and b in self.struct0:
                    if b in self.struct0[a]:
                        return True
                    else:
                        return False
            case 1:
                if a < self.struct1.shape[0] and b < self.struct1.shape[1]:
                    if self.struct1[a, b]:
                        return True
                    else:
                        return False

    def get_grau(self, vertice: int):
        match self.tipo:
            case 0:
                if vertice in self.struct0:
                    grau = 0
                    for i in self.struct0[vertice]:
                        if i != vertice:
                            grau += 1
                        else:
                            grau += 2
                    return grau
                else:
                    return None
            case 1:
                if vertice < self.struct1.shape[0]:
                    grau = sum(self.struct1[vertice]) + self.struct1[vertice]
                    return grau
                else:
                    return None

    def add_vertice(self):
        match self.tipo:
            case 0:
                temp_v = vertex(self.v_id_count)
                self.v_id_count += 1
                self.v_list.append(temp_v)
                self.struct0.update({temp_v.id_v: []})
            case 1:
                temp_v = vertex(self.v_id_count)
                self.v_id_count += 1
                self.v_list.append(temp_v)
                self.struct1 = np.pad(self.struct1, ((0, 1), (0, 1)),
                                      mode='constant', constant_values=0)

    def add_edge(self, par_list: list[tuple[int, int]]):
        # check se o par de vertices existe
        for par in par_list:
            match self.tipo:
                case 0:
                    if par[0] in self.struct0 and par[1] in self.struct0:
                        temp_e = edge(self.e_id_count, par)
                        self.e_id_count += 1
                        self.e_list.append(temp_e)
                        if par[0] == par[1]:  # Laços aparecem apenas uma vez
                            self.struct0[par[0]].append(par[1])
                        else:
                            self.struct0[par[0]].append(par[1])
                            self.struct0[par[1]].append(par[0])
                    else:
                        print('Vértice não encontrado - add_edge')
                case 1:
                    if par[0] < self.struct1.shape[0] and par[1] < self.struct1.shape[1]:
                        temp_e = edge(self.e_id_count, par)
                        self.e_id_count += 1
                        self.e_list.append(temp_e)
                        if par[0] == par[1]:  # Laços aparecem apenas uma vez
                            self.struct1[par[0], par[1]] += 1
                        else:
                            self.struct1[par[0], par[1]] += 1
                            self.struct1[par[1], par[0]] += 1
                    else:
                        print('Vértice não encontrado - add_edge')


def create_complete(n: int) -> grafo:
    """
    Lab. 02 - Exercício 2.1
    Essa função cria Grafos completos de tamanho N.
    essa função cria apenas grafos com estruturas de adjacência
    :param n:
    :return graph:
    """
    G = grafo(0)
    for i in range(n):
        G.add_vertice()

    # Essa função cria Grafos completos de tamanho n_completo
    for v1 in range(n):
        for v2 in range(n):
            if v1 != v2 and v2 > v1:
                G.add_edge([(v1, v2)])

    return G


def create_k_regular(n: int, k: int) -> grafo:
    """
    Essa função cria grafos k regulares de ordem n.
    :param n:
    :param k:
    :return grafo:
    """
    G = grafo(0)
    for nv in range(n):
        G.add_vertice()

    for v1 in range(n):
        v2 = 0
        explode = 0
        dif_a = k - G.get_grau(v1)
        dif_b = k - G.get_grau(v2)
        while dif_a > 0:
            if dif_b > 0:
                if dif_a == 1 and v1 == v2:
                    v2 += 1
                else:
                    G.add_edge([(v1, v2)])
                    v2 += 1
            else:
                v2 += 1
            explode += 1
            if explode > n*n+k*k:
                print('exploded')
                return None
    return G
