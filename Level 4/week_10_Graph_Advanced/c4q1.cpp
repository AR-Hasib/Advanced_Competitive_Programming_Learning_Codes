/* https://codeforces.com/problemset/problem/510/c */

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

    if (topo.size() < n) {
        // Graph has a cycle
        return {};
    }else return topo;
}

void solve(){
    int n; cin>>n;
    vector<string> inp(n);
    for(int i=0; i<n; i++) cin>>inp[i];

    vector<vector<int>>adj(26);
    for(int i=0; i<n-1; i++){
        int diff = false;
        // find first letter which is different 
        for(int j=0; j<min(inp[i].size(), inp[i+1].size()); j++){
            if(inp[i][j] != inp[i+1][j]){
                diff = true;    // found
                // make a direction
                adj[inp[i][j]-'a'].push_back(inp[i+1][j]-'a');
                break;
            }
        }

        if(!diff && inp[i].size()>inp[i+1].size()){
            cout<<"Impossible"<<endl;
            return;
        }
    }

    vector<int> topo = topoKahn(adj);
    if(topo.empty()) cout<<"Impossible"<<endl;
    else{
        for(int i=0; i<26; i++){
            cout<<char(topo[i]+'a');
        }
        cout<<endl;
    }

}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}