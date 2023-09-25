// Solução proposta para o problema "332 - Reconstruct Itinerary"

class Solution
{
    // Função de busca em profundidade
    void dfs(unordered_map<string, multiset<string>> &adj, vector<string> &result, string s)
    {
        // Enquanto houver destinos conectados ao aeroporto atual
        while (adj[s].size())
        {
            string v = *(adj[s].begin()); // Obtenha o próximo destino
            adj[s].erase(adj[s].begin()); // Remova este destino da lista
            dfs(adj, result, v);          // Explore recursivamente este destino
        }
        result.push_back(s); // Adicione o aeroporto atual ao resultado
    }

public:
    // Função principal para encontrar o itinerário
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, multiset<string>> adj; // Crie uma lista de adjacência para representar os voos
        for (vector<string> &t : tickets)
            adj[t[0]].insert(t[1]); // Adicione cada destino ao multiconjunto conectado ao seu aeroporto de origem

        vector<string> result;
        dfs(adj, result, "JFK");               // Inicie a busca em profundidade a partir de JFK (Aeroporto Internacional John F. Kennedy)
        reverse(result.begin(), result.end()); // Inverta o resultado para obter o itinerário correto

        return result;
    }
};