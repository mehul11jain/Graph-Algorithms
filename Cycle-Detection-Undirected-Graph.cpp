#include<bits/stdc++.h>

class Graph{
    int V;
    std::vector<int>* adj;
    public:
        Graph(int n_v){
            V = n_v;
            adj = new std::vector<int>[n_v];
        }
        std::vector<int>* get_adjacency_list(){
            return adj;
        }
        void print_adjacency_list(){
            for(int i=0;i<V;i++){
                std::cout<<i<<": ";
                for(auto it = adj[i].begin();it!=adj[i].end();it++){
                    std::cout<<*it<<" ";
                }
                std::cout<<"\n";
            }
        }
        bool is_cyclic_bfs(){
            
            std::vector<bool> visited;
            std::queue<int> q;
            q.push(0);
            visited[0] = 1;
            std::vector<int> parent(V,-1);

            while(!q.empty()){
                int curr = q.front();
                q.pop();                
                for(auto it=adj[curr].begin();it!=adj[curr].end();it++){
                    if(!visited[*it]){
                        q.push(*it);
                        parent[*it] = curr;
                        visited[*it] = 1;
                    }
                    else if(*it != parent[curr])
                        return 1;
                }                
            }            
            return 0;
        }
        bool dfs(int curr,std::vector<bool>& visited,int parent){
            visited[curr] = 1;            
            for(auto it=adj[curr].begin();it!=adj[curr].end();it++){                
                if(!visited[*it]){
                    if(dfs(*it,visited,curr))
                        return 1;
                }
                else if(*it != parent)
                    return 1;
            }            
            return 0;            
        }
        bool is_cyclic_dfs(){
            std::vector<bool> visited(V,0);
            bool ans = 1;            
            for(int i=0;i<V;i++){
                if(!visited[i])
                    ans &= dfs(i, visited,-1);
            }
            return ans;            
        }
};
int main(){
    int V;
    std::cin>>V;
    Graph G(V);
    std::vector<int>* adj = G.get_adjacency_list();
    int q; 
    std::cin>>q;    
    for(int i=0;i<q;i++){
        int s,d;
        std::cin>>s>>d;
        adj[s].push_back(d); // undirected Graph.
        adj[d].push_back(s);
    }
    // G.print_adjacency_list();
    if(G.is_cyclic_dfs())
        std::cout<<"CYCLE FOUND!!!\n";
    else
        std::cout<<"-1\n";
    if (G.is_cyclic_bfs())
        std::cout << "CYCLE FOUND!!!\n";
    else
        std::cout << "-1\n";
    return 0;
}