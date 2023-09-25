// Solução proposta para o exercício "847 - Shortest Path Visiting All Nodes"

class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int numNodes = graph.size();               // Número total de nós no grafo
        queue<pair<int, pair<int, int>>> bfsQueue; // Inicializando a fila para realizar a busca em largura (BFS)
        set<pair<int, int>> visitedStates;         // Conjunto de estados visitados

        // Inicialização da BFS com todos os nós iniciais
        for (int startNode = 0; startNode < numNodes; startNode++)
        {
            // Cada estado consiste em (nó atual, (máscara de nós visitados, distância até agora))
            bfsQueue.push({startNode, {1 << startNode, 0}});
            visitedStates.insert({startNode, 1 << startNode});
        }

        int finalMask = (1 << numNodes) - 1; // Máscara final com todos os nós visitados

        while (!bfsQueue.empty())
        {
            int currentNode = bfsQueue.front().first;             // Nó atual
            int currentMask = bfsQueue.front().second.first;      // Máscara de nós visitados
            int currentDistance = bfsQueue.front().second.second; // Distância até agora

            bfsQueue.pop();

            // Verifica se todos os nós foram visitados
            if (currentMask == finalMask)
                return currentDistance; // Retorna a distância mínima

            // Itera pelos vizinhos do nó atual
            for (auto neighbor : graph[currentNode])
            {
                int newMask = currentMask;
                newMask |= (1 << neighbor); // Marca o vizinho como visitado na máscara

                // Verifica se o estado (vizinho, nova máscara) já foi visitado
                if (visitedStates.find({neighbor, newMask}) == visitedStates.end())
                {
                    visitedStates.insert({neighbor, newMask});
                    bfsQueue.push({neighbor, {newMask, currentDistance + 1}}); // Adiciona o vizinho na fila com a nova distância
                }
            }
        }

        return -1; // Caso não seja possível alcançar todos os nós
    }
};
