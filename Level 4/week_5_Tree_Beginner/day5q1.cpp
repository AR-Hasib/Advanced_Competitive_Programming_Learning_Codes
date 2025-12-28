/* https://cses.fi/problemset/task/1131 */

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

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    VV(int) edges(n);
    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    function<void(int, int, vector<int>&)> DFS;
    DFS = [&] (int node, int parent, vector<int>& dist){
        if(parent == -1) dist[node] = 0;
        else dist[node] = dist[parent]+1;

        for(auto &child:edges[node]){
            if(child != parent) DFS(child, node, dist);
        }
    };

    function<int(vector<int>&)> maxDistancedNode;
    maxDistancedNode = [&] (vector<int>& dist){
        int node = 0;
        for(int i=0; i<n; i++){
            if(dist[i] >= dist[node]) node = i;
        }
        return node;
    };

    int x = 0;
    vector<int> distX(n);
    DFS(x, -1, distX);

    int y = maxDistancedNode(distX);
    vector<int> distY(n);
    DFS(y, -1, distY);
    int z = maxDistancedNode(distY);
    
    cout<<distY[z]<<endl;
    return 0;
}