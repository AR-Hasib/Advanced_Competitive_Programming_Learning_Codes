/* the tree has n nodes, the edges are given */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

void dfsTraversal(int currNode, int parent, vector<vector<int>> &adj, vector<int> &dfs){
    dfs.push_back(currNode);
    for(int child : adj[currNode]){
        if(child != parent) dfsTraversal(child, currNode, adj, dfs);
    }
    return;
}

void bfsTraversal(int root, int n, vector<vector<int>> &adj, vector<int> &bfs){
    queue<int> q;
    vector<bool> visited(n, false);
    q.push(root);
    visited[root] = true;
    while(!(q.empty())){
        int currNode = q.front();
        q.pop();
        bfs.push_back(currNode);
        for(int child : adj[currNode]){
            if(!visited[child]){
                visited[child] = true;
                q.push(child);
            }
        }
    }
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<vector<int>> adj(n);
    // let there is the edges between u and v, total edge = n-1
    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v;
        u--; v--;   // 1 -> 0 base indexing
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 

    int root = 0;
    vector<int> dfs, bfs;
    dfsTraversal(root, -1, adj, dfs);
    for(int x : dfs) cout << x+1 << ' ';  // 0 -> 1 base indexing
    cout << endl;

    bfsTraversal(root, n, adj, bfs);
    for(int x : bfs) cout << x+1 << ' ';
    cout << endl;

    return 0;
}