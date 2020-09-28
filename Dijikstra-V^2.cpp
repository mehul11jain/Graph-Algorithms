#include <bits/stdc++.h>
class Graph
{
    int V;
    std::vector<std::pair<int, int>> *adj;

public:
    Graph(int n_v)
    {
        V = n_v;
        adj = new std::vector<std::pair<int, int>>[n_v];
    }
    std::vector<std::pair<int, int>> *get_adjacency_list()
    {
        return adj;
    }
    void print_adjacency_list()
    {
        for (int i = 0; i < V; i++)
        {
            std::cout << i << ": ";
            for (auto it = adj[i].begin(); it != adj[i].end(); it++)
            {
                std::cout << (*it).first << " ";
            }
            std::cout << "\n";
        }
    }
    int min_distance(std::vector<int> &distance, std::vector<bool> &visited)
    {
        int res = INT_MAX;
        int idx = -1;
        for (int i = 0; i < distance.size(); i++)
        {
            if (!visited[i] && distance[i] < res)
            {
                res = distance[i];
                idx = i;
            }
        }
        return idx;
    }
    std::vector<int> dijikstra(int src)
    {
        std::vector<int> dist(V, INT_MAX);
        std::vector<bool> visited(V, 0);
        dist[src] = 0;
        for (int i = 0; i < V; i++)
        {
            int u = min_distance(dist, visited);
            visited[u] = 1;
            for (auto it = adj[u].begin(); it != adj[u].end(); it++)
            {
                if (dist[u] != INT_MAX && dist[(*it).first] > dist[u] + (*it).second)
                    dist[(*it).first] = dist[u] + (*it).second;
            }
        }
        return dist;
    }
};
int main()
{
    int V;
    std::cin >> V;
    Graph G(V);
    std::vector<std::pair<int, int>> *adj = G.get_adjacency_list();
    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++)
    {
        int s, d, w;
        std::cin >> s >> d >> w;
        adj[s].push_back(std::make_pair(d, w)); // undirected Graph.
        adj[d].push_back(std::make_pair(s, w));
    }
    std::vector<int> res = G.dijikstra(0);
    int i = 0;
    for (auto x : res)
    {
        std::cout << i << " " << x << std::endl;
        i++;
    }
    return 0;
}