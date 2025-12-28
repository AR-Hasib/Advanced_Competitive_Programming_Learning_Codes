/* https://codeforces.com/problemset/problem/744/A */

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
    int n, m, k; cin>>n>>m>>k;
    VV(int) edges(n);
    vector<bool> isGov(n, false);
    for(int i=0; i<k; i++){
        int x; cin>>x;
        isGov[x-1] = true;
    }
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<int> gov, nonGov;

    auto dfs = [&] (auto &&dfs, int node, int &sz, bool &flag)->void{
        sz++;
        if(isGov[node]) flag = true;
        visited[node] = true;
        for(int &neigh:edges[node]){
            if(!visited[neigh]) dfs(dfs, neigh, sz, flag);
        }
    };

    for(int node=0; node<n; node++){
        if(!visited[node]){
            int sz = 0;
            bool flag = false;
            dfs(dfs, node, sz, flag);
            if(flag)
                gov.push_back(sz);
            else
                nonGov.push_back(sz);
        }
    }

    int maxGovIdx = 0;
    for(int i=0; i<gov.size(); i++){
        if(gov[i] > gov[maxGovIdx]) maxGovIdx = i;
    }

    for(int i:nonGov){
        gov[maxGovIdx] += i;
    }

    ll ans = 0;
    for(auto i:gov){
        ans += ((i*(i-1))/2);
    }
    ans -= m;
    cout<<ans<<endl;
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