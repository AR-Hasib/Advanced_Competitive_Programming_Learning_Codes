/* https://codeforces.com/contest/1037/problem/D */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ll long long
#define ld long double
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define precision fixed<<setprecision
#define toLDouble static_cast<long double>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define setAll(x, y) memset(x, y, sizeof(x))
#define printVector(vctr) for(auto &vlu:vctr) cout<<vlu<<" "; cout<<endl;
#define VV(x) vector<vector<x>>

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void bfsTraversal(int root, int n, vector<vector<int>> &adj, vector<int> &bfs){
    vector<int> visited(n+1, false);
    visited[0]=true;
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
    
    int n; cin>>n;
    VV(int) edges(n+1);
    for(int i=2; i<=n; i++){
        int u, v; cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<int> order(n);

    for(int i=0; i<n; i++) cin>>order[i];

    vector<int> index(n+1);
    for(int i=0; i<n; i++){
        index[order[i]] = i;
    }
    
    for(int i=1; i<=n; i++){
        if(edges[i].size() <= 1) continue;
        sort(edges[i].begin(), edges[i].end(), [&](int a, int b){
            return index[a] < index[b];
        });
    }

    vector<int> bfs;
    bfsTraversal(1, n, edges, bfs);
    if(bfs == order) yes;
    else no;
    // printVector(bfs);

    return 0;
}