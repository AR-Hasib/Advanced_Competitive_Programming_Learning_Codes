/* https://leetcode.com/problems/min-cost-to-connect-all-points/description/ */

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

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> edges;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;

                int x1 = points[i][0], x2 = points[j][0];
                int y1 = points[i][1], y2 = points[j][1];

                int cost = abs(x1-x2) + abs(y1-y2);

                edges.push_back({cost, {i, j}});
            }
        }

        UnionFind dsu(n);
        sort(edges.begin(), edges.end(), [&](auto a, auto b){
            return a.first<b.first;
        });

        int total = 0;

        for(auto &[cost, uv]:edges){
            auto [u, v] = uv;
            if(dsu.isSameSet(u, v)) continue;
            dsu.unionSet(u, v);
            total += cost;
        }
        return total;
    }
};
