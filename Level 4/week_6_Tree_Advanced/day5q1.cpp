/* https://codeforces.com/problemset/problem/1092/F */

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
    vector<int> a(n);
    VV(int) edges(n);
    for(auto &i : a) cin>>i;
    for(int i=2; i<=n; i++){
        int u, v; cin>>u>>v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> sumOfA(n, 0), finalSum(n, 0);

    auto dfs = [&] (auto &&dfs, int node, int parent) -> void{
        sumOfA[node] = a[node];
        for(int &child:edges[node]){
            if(child != parent){
                dfs(dfs, child, node);

                // contribution
                sumOfA[node] += sumOfA[child];
                finalSum[node] += finalSum[child] + sumOfA[child];
            }
        }
    };
    dfs(dfs, 0, -1);

    auto changeRoot = [&] (int newRoot, int oldRoot) -> void{
        // removing the contribution of new root from old root
        sumOfA[oldRoot] -= sumOfA[newRoot];
        finalSum[oldRoot] -= finalSum[newRoot] + sumOfA[newRoot];

        // adding the contribution of old root to new root
        sumOfA[newRoot] += sumOfA[oldRoot];
        finalSum[newRoot] += finalSum[oldRoot] + sumOfA[oldRoot];
    };

    int ans = 0;
    auto reroot = [&] (auto &&reroot, int node, int parent) -> void{
        ans = max(ans, finalSum[node]);
        for(int &child:edges[node]){
            if(child != parent){
                changeRoot(child, node);
                reroot(reroot, child, node);
                changeRoot(node, child);
            }
        }
    };
    reroot(reroot, 0, -1);
    cout<<ans<<endl;

    return 0;
}