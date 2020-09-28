#include <bits/stdc++.h>
class Graph
{
    int V;
    std::vector<int> *adj;

public:
    Graph(int n_v)
    {
        V = n_v;
        adj = new std::vector<int>[n_v];
    }
    std::vector<int> *get_adjacency_list()
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
                std::cout << *it << " ";
            }
            std::cout << "\n";
        }
    }
    bool is_cyclic_bfs()
    {
        int indegree[V];
        for (int i = 0; i < V; i++)
            indegree[i] = 0;
        for (int i = 0; i < V; i++)
        {
            for (auto x : adj[i])
            {
                indegree[x]++;
            }
        }
        int ans = 0;
        std::queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (auto it = adj[curr].begin(); it != adj[curr].end(); it++)
            {
                if (--indegree[*it] == 0)
                {
                    q.push(*it);
                }
            }
            ans++;
        }
        if (ans == V)
            return 0;
        return 1;
    }
    bool is_cyclic_dfs()
    {
        return 0;
    }
};
int main()
{
    int V;
    std::cin >> V;
    Graph G(V);
    std::vector<int> *adj = G.get_adjacency_list();
    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++)
    {
        int s, d;
        std::cin >> s >> d;
        adj[s].push_back(d); // directed Graph.
    }
    // G.print_adjacency_list();
    // if (G.is_cyclic_dfs())
    //     std::cout << "CYCLE FOUND!!!\n";
    // else
    //     std::cout << "-1\n";
    if (G.is_cyclic_bfs())
        std::cout << "CYCLE FOUND!!!\n";
    else
        std::cout << "-1\n";
    return 0;
}