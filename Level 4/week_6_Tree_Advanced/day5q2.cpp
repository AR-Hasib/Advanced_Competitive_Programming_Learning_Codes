/* https://codeforces.com/contest/1324/problem/F */

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

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<int> val(n);
    for(int i=0; i<n; i++){
        int x; cin>>x;
        val[i] = x==0 ? -1:1;
    }

    VV(int) edges(n);
    for(int i=2; i<=n; i++){
        int u, v; cin>>u>>v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> dp(n, 0), ans(n, 0);
    auto dfs = [&] (auto &&dfs, int node, int parent) -> void{
        dp[node] = val[node];
        for(auto &child:edges[node]){
            if(child != parent){
                dfs(dfs, child, node);
                dp[node] += max(0, dp[child]);
            }
        }
    };
    dfs(dfs, 0, -1);

    auto changeRoot = [&] (int oldRoot, int newRoot) -> void{
        dp[oldRoot] -= max(0, dp[newRoot]);
        dp[newRoot] += max(0, dp[oldRoot]);
    };

    auto reroot = [&] (auto &&reroot, int node, int parent) -> void{
        ans[node] = dp[node];
        for(auto &child:edges[node]){
            if(child != parent){
                changeRoot(node, child);
                reroot(reroot, child, node);
                changeRoot(child, node);
            }
        }
    };
    reroot(reroot, 0, -1);

    printVector(ans);
    
    return 0;
}