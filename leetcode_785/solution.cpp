// Solução proposta para o problema "785 - Is Graph Bipartite?"

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> adjacencyList(n); // Lista de adjacência para representar o grafo

        // Preencha a lista de adjacência com as conexões do grafo
        for (int i = 0; i < n; i++)
        {
            for (auto x : graph[i])
            {
                adjacencyList[i].push_back(x);
            }
        }

        vector<int> colored(n, -1); // Vetor para rastrear as cores dos nós (-1 indica não colorido)

        for (int i = 0; i < n; i++)
        {
            if (colored[i] == -1)
            {
                queue<pair<int, int>> q; // Fila para realizar a busca em largura (BFS)

                q.push({i, 0}); // Inicialize o nó 0 com a cor 0
                colored[0] = 0;

                while (!q.empty())
                {
                    int node = q.front().first;
                    int color = q.front().second;
                    q.pop();

                    for (auto x : adjacencyList[node])
                    {
                        // Vizinho não colorido
                        if (colored[x] == -1)
                        {
                            colored[x] = !color; // Alternar a cor (0 para 1, 1 para 0)
                            q.push({x, colored[x]});
                        }
                        // Vizinho colorido com a mesma cor do nó atual -> não bipartido
                        else if (colored[x] == color)
                        {
                            return false;
                        }
                    }
                }
            }
        }

        return true; // O grafo é bipartido
    }
};
