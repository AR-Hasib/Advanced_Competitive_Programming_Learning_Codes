/* https://codeforces.com/contest/1882/problem/D */

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

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(auto &i:a) cin>>i;

    vector<vector<int>> edges(n);
    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> subtreeSize(n, 0);
    function<void(int, int)> DFS1 = [&] (int node, int parent){
        subtreeSize[node] = 1;
        for(auto &child:edges[node]){
            if(child != parent){
                DFS1(child, node);
                subtreeSize[node] += subtreeSize[child];
            }
        }
    };
    DFS1(0, -1);

    // storing the cost needed to make equal all the nodes of a subtree assuming the root as 0
    vector<int> dp(n, 0);
    function<void(int, int)> DFS2 = [&] (int node, int parent){
        for(auto &child:edges[node]){
            if(child != parent){
                DFS2(child, node);
                dp[node] += (a[node]^a[child])*subtreeSize[child] + dp[child];
            }
        }
    };
    DFS2(0, -1);

    vector<int> ans(n, 0);
    // rerooting and storing the answer
    function<void(int, int)> DFS3 = [&] (int node, int parent){
        ans[node] = dp[node];
        for(auto &child:edges[node]){
            if(child == parent) continue;

            // removing the contribution of the child as it will be the current root
            dp[node] -= ((a[node]^a[child])*subtreeSize[child] + dp[child]);
            subtreeSize[node] -= subtreeSize[child]; // as node lose the current child(becomes parent)
            // so the node (parent of the child) is now the child of this current child
            dp[child] += ((a[node]^a[child])*subtreeSize[node] + dp[node]);
            subtreeSize[child] += subtreeSize[node];

            DFS3(child, node);

            // we are going back so give back their previous values
            subtreeSize[child] -= subtreeSize[node];
            dp[child] -= ((a[node]^a[child])*subtreeSize[node] + dp[node]);

            subtreeSize[node] += subtreeSize[child];
            dp[node] += ((a[node]^a[child])*subtreeSize[child] + dp[child]);
        }
    };
    DFS3(0, -1);

   printVector(ans);
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}