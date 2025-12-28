/* https://codeforces.com/problemset/problem/1263/D */

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

void solve(){
    int n; cin>>n;
    int m = n+26;
    VV(int) edges(m);
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(char ch:s){
            edges[i].push_back(ch-'a'+n);
            edges[ch-'a'+n].push_back(i);
        }
    }

    int components = 0;
    vector<bool> visited(m, false);
    auto dfs = [&] (auto &&dfs, int node)->void{
        visited[node] = true;
        for(auto &neigh:edges[node]){
            if(!visited[neigh]) dfs(dfs, neigh);
        }
    };

    for(int node=0; node<m; node++){
        if((edges[node].size()>0) && (!visited[node])){
            components++;
            dfs(dfs, node);
        }
    }
    cout<<components<<endl;
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