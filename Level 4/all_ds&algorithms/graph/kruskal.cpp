#include <bits/stdc++.h>
using namespace std;

class UnionFind{
    private: vector<int> p, rank;
    public: 
        UnionFind(int n){
            rank.assign(n, 0); p.assign(n, 0);
            iota(p.begin(), p.end(), 0);    // parent of each node set to itself
        }

        int findSet(int i){		// return the parent(root) of the set i belongs to
            return (p[i] == i) ? i:p[i] = findSet(p[i]);
        }
        bool isSameSet(int i, int j){
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j){
            if(!isSameSet(i, j)){
                int x = findSet(i), y = findSet(j);
                if(rank[x] > rank[y]) p[y] = x;
                else{
                    p[x] = y;
                    if(rank[x] == rank[y]) rank[y]++;
                }
            }
        }
};

/* to implement kruskal's algorithm, we need dsu
the algorithm is: sort all the edges and go through them in ascendind order and check
if the nodes connected by the edges are not already connected, take that edge */

vector<vector<int>> kruskalAlgo(vector<vector<int>> &edges, int n){
    vector<vector<int>> mst; // edge, node1, node2
    UnionFind krus(n);  // dsu template needed
    sort(edges.begin(), edges.end(), [&](auto a, auto b){
        return a[0]<b[0]; });

    for(auto &ed:edges){
        int wt = ed[0], node1 = ed[1], node2 = ed[2];
        if(krus.isSameSet(node1, node2)) continue;
        krus.unionSet(node1, node2);
        mst.push_back(ed);
    }
    return mst;
}