/* https://codeforces.com/problemset/problem/862/b */

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

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    VV(int) edges(n);
    for(int i=2; i<=n; i++){
        int u, v; cin>>u>>v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> col = {0, 0};
    auto dfs = [&] (auto &&dfs, int node, int parent, int color) -> void{
        col[color]++;
        for(auto &child:edges[node]){
            if(child != parent) dfs(dfs, child, node, color ^ 1);
        }
    };
    dfs(dfs, 0, -1, 1);

    cout<<(col[0]*col[1])-(n-1)<<endl;

    return 0;
}