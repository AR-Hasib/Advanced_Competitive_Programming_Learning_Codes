/* https://codeforces.com/problemset/problem/1593/E */

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

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n, k; cin>>n>>k;
    vector<int> degree(n, 0);
    vector<vector<int>> edges(n);
    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
        degree[u]++, degree[v]++;
    }

    int removed = 0;
    queue<int> leafs;
    for(int i=0; i<n; i++){
        if(degree[i]<=1) leafs.push(i); 
    }

    while((!leafs.empty()) && (k--)){
        int sz = leafs.size();
        for(int i=0; i<sz; i++){
            int currLeaf = leafs.front();
            leafs.pop();
            // degree[currLeaf]--; // no need for this problem
            removed++;
            for(auto &eg:edges[currLeaf]){
                degree[eg]--;
                if(degree[eg] == 1) leafs.push(eg);
            }
        }
    }
    cout<<n-removed<<endl;
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