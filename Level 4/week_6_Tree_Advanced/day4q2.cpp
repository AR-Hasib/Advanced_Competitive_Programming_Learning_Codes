/* https://cses.fi/problemset/task/1133 */

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

    vector<int> subtreeSize(n, 0), dist(n, 0), ans(n, 0);

    auto dfs = [&] (auto &&dfs, int node, int parent)->void{
        subtreeSize[node] = 1;
        for(auto &child:edges[node]){
            if(child != parent){
                dfs(dfs, child, node);
                subtreeSize[node] += subtreeSize[child];
                dist[node] += (subtreeSize[child] + dist[child]);
            }
        }
    };
    dfs(dfs, 0, -1);
    
    auto reroot = [&] (auto &&reroot, int node, int parent)->void{
        ans[node] = dist[node];

        for(auto &child:edges[node]){
            if(child != parent){
                // removing and adding the contribution -> child=new root, node=old root
                dist[node] -= (subtreeSize[child] + dist[child]);
                subtreeSize[node] -= subtreeSize[child];

                dist[child] += (subtreeSize[node] + dist[node]);
                subtreeSize[child] += subtreeSize[node];

                reroot(reroot, child, node);

                subtreeSize[child] -= subtreeSize[node];
                dist[child] -= (subtreeSize[node] + dist[node]);

                subtreeSize[node] += subtreeSize[child];
                dist[node] += (subtreeSize[child] + dist[child]);
            }
        }
    };
    reroot(reroot, 0, -1);

    for(auto &i:ans) cout<<i<<" ";

    return 0;
}