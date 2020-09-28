#include <bits/stdc++.h>
class Graph
{
    int V;
    std::vector<std::pair<int,std::pair<int, int>>> *Edges;

public:
    Graph(int n_v,int n_e)
    {
        V = n_v;
        Edges = new std::vector<std::pair<int, std::pair<int, int>>>[n_e];
    }
    std::vector<std::pair<int, std::pair<int, int>>> *get_Edge_list()
    {
        return Edges;
    }
    std::vector<int> Bellman_Ford(int src){
        std::vector<int> dist(V,INT_MAX);
        dist[src] = 0;
        for(int i=0;i<V-1;i++){
            for(auto E : *Edges){
                int s = E.first;
                int d = E.second.second;
                if(dist[s] !=INT_MAX && dist[d] > dist[s]+E.second.first)
                    dist[d] = dist[s]+E.second.first;
            }
        }
        for (auto E : *Edges)
        { // Detects negative cycle if present in the graph.
            int s = E.first;
            int d = E.second.second;
            if (dist[s] != INT_MAX && dist[d] > dist[s] + E.second.first)
                return {};
        }
        return dist;        
    }    
};
int main()
{
    int V,E;
    std::cin >> V >> E;
    Graph G(V,E);
    std::vector<std::pair<int, std::pair<int, int>>> *Edges = G.get_Edge_list();
    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++)
    {
        int s, d, w;
        std::cin >> s >> d >> w;
        
        (*Edges).push_back(std::make_pair(s,std::make_pair(w, d))); // directed Graph.        
    }
    std::vector<int> res = G.Bellman_Ford(0);
    if(res.empty()) 
        std::cout<<"Negative weight cycle"<<std::endl;
    int i = 0;
    for (auto x : res)
    {
        std::cout << i << " " << x << std::endl;
        i++;
    }
    return 0;
}