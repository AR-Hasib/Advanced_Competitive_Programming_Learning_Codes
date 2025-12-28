/* https://codeforces.com/problemset/problem/369/C */

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

int DFS(int node, int parent, vector<vector<int>>& edges, vector<int>& roads, vector<int>& subTreeSum){
    if(roads[node] == 1){
        subTreeSum[node]++;
    }

    for(auto &child : edges[node]){
        if(child != parent){
            subTreeSum[node] += DFS(child, node, edges, roads, subTreeSum);
        }
    }
    return subTreeSum[node];
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<vector<int>> edges(n+1);
    vector<int> roads(n+1, 0);
    for(int i=0; i<n-1; i++){
        int a, b, r; cin>>a>>b>>r;
        edges[a].push_back(b);
        edges[b].push_back(a);
        if(r==2){
            roads[a]=1; // need repair
            roads[b]=1;
        }
    }

    vector<int> subTreeSum(n+1, 0);
    DFS(1, 0, edges, roads, subTreeSum);
    int total = 0;
    vector<int> ans;
    for(int i=1; i<=n; i++){
        if(subTreeSum[i] == 1){
            ans.push_back(i);
            total++;
        }
    }
    cout<<total<<endl;
    for(auto i:ans) cout<<i<<" ";
    cout<<endl;

    return 0;
}