#include <bits/stdc++.h>
using namespace std;


// using DFS
void topoDfs(int node, vector<vector<int>> &edges, vector<int> &ans, vector<bool> &visited){
    visited[node] = true;
    for(int u:edges[node]){
        if(!visited[u]) topoDfs(u, edges, ans, visited);
    }
    ans.push_back(node);
}
vector<int> topoSortDfs(vector<vector<int>> &edges, vector<bool> &visited){
    vector<int> ans;
    for(int i=0; i<edges.size(); i++){
        if(!visited[i]) topoDfs(i, edges, ans, visited);
    }
    reverse(ans.begin(), ans.end());
}



// using BFS - Kahn's Algorithm
// if kahn's algo return an empty vector, there is a cycle in the graph
vector<int> topoKahn(vector<vector<int>> &edges){
    int n = edges.size();
    vector<int> indegree(n, 0);
    for(int u=0; u<n; u++)
        for(int v:edges[u]) indegree[v]++;

    queue<int> q;
    for(int u=0; u<n; u++)
        if(indegree[u] == 0) q.push(u);
    
    vector<int> topo;
    while(!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(int v:edges[u]){
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    }
    return topo;
}
