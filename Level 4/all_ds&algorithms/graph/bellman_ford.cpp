#include <bits/stdc++.h>
using namespace std;
int INF = INT_MAX/2;

vector<int> bellman_ford(int n, int source, vector<vector<int>> &edges){
    // edges vector stores edges like this -> u,v,dist
    vector<int> dist(n, INF);
    dist[source] = 0;
    for(int i=0; i<n; i++){
        bool any = false;
        for(auto &edge:edges){
            int u=edge[0], v=edge[1], wt=edge[2];
            if(dist[u]+wt < dist[v]){
                dist[v] = dist[u]+wt;
                any = true;
            }
        }
        if(!any) break; // no change indicates all edges already relaxed
        if(i==n-1) return{}; // negative cycle
    }
}

