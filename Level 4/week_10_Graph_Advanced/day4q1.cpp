/* https://codeforces.com/problemset/problem/427/C */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define int long long
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

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

vector<vector<int>> kosaraju(int n, const vector<vector<int>>& graph) {
    vector<vector<int>> revGraph(n);
    vector<bool> visited(n, false);
    vector<int> order;

    auto dfs1 = [&](auto&& dfs1, int u) -> void {
        visited[u] = true;
        for (int v : graph[u]) {
            revGraph[v].push_back(u);
            if (!visited[v])
                dfs1(dfs1, v);
        }
        order.push_back(u);
    };

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs1(dfs1, i);
    }

    vector<vector<int>> sccs;
    fill(visited.begin(), visited.end(), false);

    auto dfs2 = [&](auto&& dfs2, int u, vector<int>& component) -> void {
        visited[u] = true;
        component.push_back(u);
        for (int v : revGraph[u]) {
            if (!visited[v])
                dfs2(dfs2, v, component);
        }
    };

    reverse(order.begin(), order.end());
    for (int u : order) {
        if (!visited[u]) {
            vector<int> component;
            dfs2(dfs2, u, component);
            sccs.push_back(component);
        }
    }

    return sccs;
}

void solve(){
    int n; cin>>n; 
    vector<int> cost(n);
    for(auto &i:cost) cin>>i;

    int m; cin>>m;
    VV(int) adj(n);
    while(m--){
        int u, v; cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
    }

    VV(int) scc = kosaraju(n, adj);
    int ways = 1;
    int totalCost = 0;

    for(auto &i:scc){
        int mn = INF, noMin = 0; // no of minimum cost's node
        for(auto &j:i){
            if(cost[j] < mn){
                mn = cost[j];
                noMin = 1;
            }else if(cost[j] == mn) noMin++;
        }
        totalCost = totalCost + mn;
        ways = (ways * noMin)%MOD;
    }

    cout<<totalCost<<" "<<ways<<endl;
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}