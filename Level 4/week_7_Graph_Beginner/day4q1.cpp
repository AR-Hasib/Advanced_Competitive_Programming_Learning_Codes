/* https://codeforces.com/contest/1167/problem/C */

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
    int n, m; cin>>n>>m;
    int k = n+m;
    VV(int) edges(k);
    for(int i=0, j=n; i<m; i++, j++){
        int num; cin>>num;
        while(num--){
            int x; cin>>x; x--;
            edges[x].push_back(j);
            edges[j].push_back(x);
        }
    }

    vector<bool> visited(k, false);
    vector<int> belongsTo(n);   // store which node belongs to which component
    map<int, int> compSize;    // store the size of components
    auto dfs = [&] (auto &&dfs, int node, int &currComp, int &size)->void{
        visited[node] = true;
        if(node < n){
            size++;
            belongsTo[node] = currComp;
        }
        for(int &neigh:edges[node]){
            if(!visited[neigh]) dfs(dfs, neigh, currComp, size);
        }
    };

    int currComp = 0;
    for(int node=0; node<n; node++){
        if(!visited[node]){
            int size = 0;
            dfs(dfs, node, currComp, size);
            compSize[currComp] = size;
            currComp++;
        }
    }

    for(int i=0; i<n; i++){
        int x = compSize[belongsTo[i]];
        cout<<x<<" ";
    }

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