/**
 * The union() and find() in the naive implementation has the worst case time complexity is linear. 
 * The trees created to represent subsets can be skewed and can become like a linked list. 
 * 
 * The above operations can be optimized to O(Log n) in worst case.
 * The idea is to always attach smaller depth tree under the root of the deeper tree. 
 * This technique is called union by rank. 
 * 
 * The second optimization to naive method is Path Compression. 
 * The idea is to flatten the tree when find() is called. 
 * When find() is called for an element x, root of the tree is returned. 
 * The find() operation traverses up from x to find root. 
 * The idea of path compression is to make the found root as parent of x 
 * so that we don’t have to traverse all intermediate nodes again 
*/
#include <bits/stdc++.h>

class DisjointSet
{
    int size;
    std::vector<int> parent;
    std::vector<int> rank;

public:
    DisjointSet(int size)
    {
        this->size = size;
        for (int i = 0; i < size; i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    int Find(int i)
    {
        // Path Compression
        if (parent[i] != i)
            parent[i] = Find(parent[i]);
        return parent[i];
    }
    void Union(int x, int y)
    {
        int xset = Find(x);
        int yset = Find(y);
        if(xset!=yset){ // Preventing skewed tree using ranks.
            if (rank[xset] > rank[yset])
                parent[yset] = xset;
            else if (rank[xset] < rank[yset])
                parent[xset] = yset;
            else
            {
                parent[xset] = yset;
                rank[yset]++;
            }
            
        }                
    }
};
int main()
{
    int v;
    std::cin >> v;
    DisjointSet D(v);
    int n_e;
    std::cin >> n_e;
    std::vector<std::pair<int, std::pair<int, int>>> Edges;
    for (int i = 0; i < n_e; i++)
    {
        int s, d, w;
        std::cin >> s >> d >> w;
        Edges.push_back(std::make_pair(w, std::make_pair(s, d)));
    }
    std::sort(Edges.begin(), Edges.end());
    int mst = 0;
    for (auto x : Edges)
    {
        if (D.Find(x.second.first) != D.Find(x.second.second))
        {
            mst += x.first;
            D.Union(x.second.first, x.second.second);
        }
    }
    std::cout << mst << std::endl;
    return 0;
}