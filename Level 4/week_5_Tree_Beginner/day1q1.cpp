/* https://codeforces.com/problemset/problem/913/B*/

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

int DFS(int node, int parent, vector<vector<int>>& edges, vector<bool>& pass){
    int nodeSize = 1;
    int leafCount = 0;
    for(int child:edges[node]){
        if(child != parent){
            int currChildSize = DFS(child, node, edges, pass);
            if(currChildSize == 1) leafCount++;
            nodeSize += currChildSize;
        }
    }

    if(leafCount >= 3) pass[node] = true;
    return nodeSize;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<vector<int>> edges(n);
    // i am using 0 base indexing

    for(int i=1; i<=n-1; i++){
        int a; cin>>a;
        a--;
        edges[i].push_back(a);
        edges[a].push_back(i);
    }
    vector<bool> pass(n, false);
    DFS(0, -1, edges, pass);

    for(int i=0; i<n-1; i++){
        if(pass[i]) continue;
        if(edges[i].size() > 1){
            no; return 0;
        }
    }
    yes;

    return 0;
}