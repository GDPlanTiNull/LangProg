def dijkstra(matriz, inicio, fim):
    Inf = 9999
    n = len(matriz)
    
    # Inicialização das estruturas de dados
    visitados = [False] * n
    distancia = [Inf] * n
    distancia[inicio] = 0
    caminho = [-1] * n
    
    # Loop principal do algoritmo
    for _ in range(n):
        u = -1
        # Encontra o vértice não visitado com menor distância
        for v in range(n):
            if not visitados[v] and (u == -1 or distancia[v] < distancia[u]):
                u = v
        if u == -1 or distancia[u] == Inf:
            break
        visitados[u] = True
        # Relaxamento das arestas
        for v in range(n):
            if distancia[u] + matriz[u][v] < distancia[v]:
                distancia[v] = distancia[u] + matriz[u][v]
                caminho[v] = u
    
    # Reconstrução do caminho
    path = []
    v = fim
    while v != -1:
        path.append(v)
        v = caminho[v]
    path.reverse()
    
    return distancia[fim], path

# Definição da matriz de pesos
Inf = 9999  # Definindo o valor para Inf

matriz = [
    [0, 5, 1, 2, Inf, Inf, Inf, Inf, Inf],
    [5, 0, Inf, Inf, Inf, Inf, Inf, Inf, 3],
    [1, Inf, 0, Inf, 1, Inf, Inf, Inf, Inf],
    [2, Inf, Inf, 0, Inf, 1, Inf, Inf, Inf],
    [Inf, Inf, 1, Inf, 0, Inf, Inf, 1, Inf],
    [Inf, Inf, Inf, 1, Inf, 0, 1, Inf, Inf],
    [Inf, Inf, Inf, Inf, Inf, 1, 0, 3, 2],
    [Inf, 1, Inf, Inf, Inf, 1, Inf, 3, 0],
    [Inf, 3, Inf, Inf, Inf, Inf, 2, Inf, 0]
]

# Chamada da função
inicio = 2
fim = 8
distancia, caminho = dijkstra(matriz, inicio, fim)
if distancia != 9999:
    print(f"Menor distância entre {inicio} e {fim}: {distancia}")
    print("Caminho:", caminho)
else:
    print(f"Não há caminho entre {inicio} e {fim}")
