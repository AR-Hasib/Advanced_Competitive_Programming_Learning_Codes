/* the tree has n nodes, the edges are given */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

////////////////////////////////////diameter 1
void dfsTraversal(int currNode, int parent, vector<vector<int>>& edges, vector<int> &maxDistLeaf){
    maxDistLeaf[currNode] = 0;
    for(int child : edges[currNode]){
        if(child != parent){
            dfsTraversal(child, currNode, edges, maxDistLeaf);  
            maxDistLeaf[currNode] = max(maxDistLeaf[currNode], 1+maxDistLeaf[child]);
        } 
    }
    return;
}

void dfsDiameter(int curr, int parent, vector<vector<int>>& edges, vector<int>& farthestLeaf, vector<int>& maxDist){
    // cases for a node {no children, 1 child, >=2 child}

    vector<int> maxLeavesInChild;
    for(int child : edges[curr]){
        if(child != parent){
            maxLeavesInChild.push_back(farthestLeaf[child]);
            dfsDiameter(child, curr, edges, farthestLeaf, maxDist);
        }
    }

    if(maxLeavesInChild.size() == 0) maxDist[curr] = 0;
    else if(maxLeavesInChild.size() == 1) maxDist[curr] = maxLeavesInChild[0]+1;
    else{
        sort(maxLeavesInChild.begin(), maxLeavesInChild.end());
        reverse(maxLeavesInChild.begin(), maxLeavesInChild.end());
        maxDist[curr] = maxLeavesInChild[0] + maxLeavesInChild[1] + 2;
    }
    return;
}

int findDiameter1(int root, int n, vector<vector<int>> &edges){
    /* this approach is a kind of very strict about the diameter defination. we find max disatnce leaf 
    node from every node, then we will go to every node and find the distance of it's 2 most distanced
    leaf. and the max among all nodes will be diameter */
    
    vector<int> maxDistLeaf(n, -1); // store the max distance of leaf from current node
    vector<int> maxDistAsLCA(n, -1); // store the max distance of a path such that 
    // current node is the LCA(Last Common Ancestor) of that path

    dfsTraversal(0, -1, edges, maxDistLeaf);
    dfsDiameter(0, -1, edges, maxDistLeaf, maxDistAsLCA);

    int diameter = 0;
    for(int i=0; i<n; i++) diameter = max(diameter, maxDistAsLCA[i]);
    return diameter;
}

///////////////////////////////////// diameter 2
void dfs(int curr, int parent, vector<vector<int>>& edges, vector<int>& level){
    if(parent == -1) level[curr] = 0;
    else level[curr] = level[parent] + 1;

    for(int child : edges[curr]){
        if(child != parent) dfs(child, curr, edges, level);
    }
}

int farthestNode(int n, vector<int>& dist){
    int farthest = 0;
    for(int i=0; i<n; i++){
        if(dist[i] > dist[farthest]) farthest = i;
    }
    return farthest;
}

int findDiameter2(int n, vector<vector<int>> &edges){
    /* this approach is bit different, used by most people, easier to implement.
    pick any node x, find the farthest node y from x, find the farthest z from y. distance between
    y and z is the diameter */

    vector<int> distX(n, -1), distY(n, -1);
    int x = 0; // set any node as x
    dfs(x, -1, edges, distX);
    int y = farthestNode(n, distX);

    dfs(y, -1, edges, distY);
    int z = farthestNode(n, distY);
    return distY[z];
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<vector<int>> edges(n);
    // let there is the edges between u and v, total edge = n-1
    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v;
        u--; v--;   // 1 -> 0 base indexing
        edges[u].push_back(v);
        edges[v].push_back(u);
    } 

    int root = 0;
    int diameter1 = findDiameter1(root, n, edges);
    int diameter2 = findDiameter2(n, edges);

    return 0;
}