/* https://codeforces.com/contest/1833/problem/E */

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
    vector<set<int>> edges(n); // values can be duplicate, we need to store unique
    for(int i=0; i<n; i++){
        int x; cin>>x;
        x--;
        edges[i].insert(x);
        edges[x].insert(i);
    }

    vector<bool> visited(n, false);
    auto dfs = [&] (auto &&dfs, int node, bool &hasLeaf)->void{
        if(edges[node].size() == 1) hasLeaf = true;
        visited[node] = true;
        for(int neigh:edges[node]){
            if(!visited[neigh]) dfs(dfs, neigh, hasLeaf);
        }
    };

    int cycle = 0, leafBranch = 0;
    for(int node=0; node<n; node++){
        if(visited[node]) continue;

        bool hasLeaf = false;
        dfs(dfs, node, hasLeaf);

        if(hasLeaf) leafBranch++;
        else cycle++;
    }

    cout<<cycle+min(1, leafBranch)<<" "<<cycle+leafBranch<<endl;
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