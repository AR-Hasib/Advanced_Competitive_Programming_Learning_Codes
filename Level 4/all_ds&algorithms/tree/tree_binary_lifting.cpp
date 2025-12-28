/* the tree has n nodes, the edges are given */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

/////////////////////////////////// BINARY LIFTING TO FIND k-th ANCESTOR /////////////////////////////
// finding parent for every node
void findParent(int node, int parent, vector<vector<int>>& adj, vector<vector<int>>& ancestor) {
    ancestor[node][0] = parent;
    for (int child : adj[node]) {
        if (child != parent) {
            findParent(child, node, adj, ancestor);
        }
    }
}

// finding 2^i-th ancestors(completing 2d vector)
void completeAncestor(int n, int LOG, vector<vector<int>>& ancestor){
    for(int i=1; i<=LOG; i++){
        for(int node=1; node<=n; node++){
            int mid = ancestor[node][i-1];
            ancestor[node][i] = ancestor[mid][i-1];
        }
    }
}

// finding k-th ancestor of node(exact querry)
int findAncestor(int node, int k, int LOG, vector<vector<int>>& ancestor){
    for(int i=0; i<=LOG; i++){
        if(k & (1<<i)) node = ancestor[node][i];
    }
    return node;
}
/////////////////////////////////////////////////////////////////////////////////////////////////

// store the level or depth of every node
void storeDepth(int node, int parent, vector<vector<int>>& adj, vector<int>& level) {
    for (int child : adj[node]) {
        if (child != parent) {
            level[child] = level[node] + 1;
            storeDepth(child, node, adj, level);
        }
    }
}

// return the last common ancestor of node u and v
int lca(int u, int v, vector<int>& level, vector<vector<int>>& ancestor, int LOG){
    if(level[u] < level[v]) swap(u, v);
    // lift both to the same level
    if(level[u] > level[v]) u = findAncestor(u, level[u]-level[v], LOG, ancestor);
    if(u == v) return u; 

    for(int i=LOG-1; i>=0; i--){
        if(ancestor[u][i] != ancestor[v][i]){
            u = ancestor[u][i];
            v = ancestor[v][i];
        }
    }
    return ancestor[u][0];
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;    
    // 1 base indexing is better for this algorithm
    vector<vector<int>> adj(n+1);
    // let there is the edges between u and v, total edge = n-1
    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 

    //////////////////////////////// FINDING ANCESTOR //////////////////////////////////////////
    int LOG = log2(n)+1;
    // ancestor[x][y] = 2^y-th ancestor of x. 
    vector<vector<int>> ancestor(n+1, vector<int>(LOG, 0));
    findParent(1, 0, adj, ancestor); // assume root is 1
    completeAncestor(n, LOG, ancestor);
    // findAncestor(5, 3); // return 3rd ancestor of node 5 
    ////////////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////// FINDING LEAST COMMON ANCESTOR //////////////////////////////
    ///////////////////////////// FINDING Distance Between two Nodes ///////////////////////////
    vector<int> level(n+1, 0);
    storeDepth(1, 0, adj, level);
    int node1, node2; // cin>>node1>>node2;
    int lastCommonAncestor = lca(node1, node2, level, ancestor, LOG);
    int distanceBetweenNode1Node2 = level[node1] + level[node2] - level[lastCommonAncestor];
    ////////////////////////////////////////////////////////////////////////////////////////////

    return 0;
}