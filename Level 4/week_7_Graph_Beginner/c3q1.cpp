/* https://codeforces.com/contest/1093/problem/D */

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

const int M = 998244353;
const int INF = LLONG_MAX /2;

long long binary_exponentiation(long long x, long long y){  // x pow y
    long long ans=1;
    while(y){
        if(y&1){        // checking whether the right most bit is 1 or not
            ans*=x; 
            ans%=M;   // 1e9 + 7
        }
        x*=x; x%=M;
        y>>=1;          // rightt shift (a>>b == a divided by (2 pow b) )
    }
    return ans%M;
}

void solve(){
    int n, m; cin>>n>>m;
    VV(int) edges(n+1);
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> color(n+1, -1);
    color[0] = 0;
    auto dfs = [&] (auto &&dfs, int node, int parent, bool& isBipartite, int &white, int &black) -> void{
        color[node] = color[parent] ^ 1;
        if(color[node]) black++;
        else white++;

        for(auto &neigh:edges[node]){
            if(color[neigh] != -1){
                if(color[neigh] == color[node]){
                    isBipartite = false;
                    return;
                }
                continue;
            }
            dfs(dfs, neigh, node, isBipartite, white, black);
        }
    };

    int ans = 1;
    for(int i=1; i<=n; i++){
        if(color[i] != -1) continue;

        bool isBipartite = true;
        int white = 0, black = 0;
        dfs(dfs, i, 0, isBipartite, white, black);

        int temp = binary_exponentiation(2, white) + binary_exponentiation(2, black);
        ans *= temp;
        ans *= isBipartite;
        ans %=M;
    }
    cout<<ans<<endl;
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