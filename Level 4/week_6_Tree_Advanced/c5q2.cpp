/* https://codeforces.com/problemset/problem/1528/A */

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

void solve(){
    int n; cin>>n;
    vector<pair<int, int>> cand(n);
    for(int i=0; i<n; i++){
        cin>>cand[i].first>>cand[i].second;
    }
    VV(int) edges(n);
    for(int i=2; i<=n; i++){
        int u, v; cin>>u>>v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    VV(int) dp(n, vector<int>(2, 0));

    auto DFS = [&] (auto&& DFS, int node, int parent)->void{
        dp[node][0] = dp[node][1] = 0;
        for(auto &child:edges[node]){
            if(child == parent) continue;

            DFS(DFS, child, node);
            
            dp[node][0] += max(dp[child][0] + abs(cand[node].first-cand[child].first),
                               dp[child][1] + abs(cand[node].first-cand[child].second));
            dp[node][1] += max(dp[child][0] + abs(cand[node].second-cand[child].first),
                               dp[child][1] + abs(cand[node].second-cand[child].second)); 
        }
        return;
    };
    DFS(DFS, 0, -1);
    cout<<max(dp[0][0], dp[0][1])<<endl;
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}