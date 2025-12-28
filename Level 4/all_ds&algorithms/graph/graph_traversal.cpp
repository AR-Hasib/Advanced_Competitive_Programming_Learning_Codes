#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

void dfsTraversal(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &dfs){
    visited[node] = 1;
    dfs.push_back(node);    // printing elements
    for(auto &neigh:adj[node]){
        if(!visited[neigh])
            dfsTraversal(neigh, adj, visited, dfs);
    }
}

void bfsTraversal(int root, int n, vector<vector<int>> &adj, vector<int> &bfs){
    vector<int> visited(n, false);
    queue<int> q;
    q.push(root);
    visited[root] = true;

    while(!q.empty()){
        int curr = q.front(); q.pop();
        bfs.push_back(curr);
        for(int &neigh:adj[curr]){
            if(!visited[neigh]){
                q.push(neigh);
                visited[neigh] = true;
            }
        }
    }
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    

    return 0;
}