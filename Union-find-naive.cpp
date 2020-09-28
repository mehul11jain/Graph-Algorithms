#include <bits/stdc++.h>

class DisjointSet{
    int size;
    std::vector<int> parent;

    public:
        DisjointSet(int size){
            this->size = size;
            for(int i=0;i<size;i++){
                parent.push_back(-1);
            }
        }
        int Find(int i){
            if(parent[i]==-1)
                return i;
            return Find(parent[i]);
        }
        void Union(int x,int y){
            int xset = Find(x);
            int yset = Find(y);
            if(xset!=yset)
            {
                parent[xset] = yset;
            }
        }

};
int main(){
    int v;
    std::cin>>v;
    DisjointSet D(v);
    int n_e;
    std::cin>>n_e;
    std::vector<std::pair<int,std::pair<int,int>>> Edges;
    for(int i=0;i<n_e;i++){
        int s,d,w;
        std::cin>>s>>d>>w;
        Edges.push_back(std::make_pair(w,std::make_pair(s,d)));
    }
    std::sort(Edges.begin(),Edges.end());
    int mst = 0;
    for(auto x : Edges){
        if(D.Find(x.second.first)!=D.Find(x.second.second)){
            mst+=x.first;
            D.Union(x.second.first,x.second.second);
        }
    }
    std::cout<<mst<<std::endl;
    return 0;
}