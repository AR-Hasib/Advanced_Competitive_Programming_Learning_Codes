/* https://codeforces.com/problemset/problem/1143/C */

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

void DFS(int node, int parent, vector<vector<int>>& edges, vector<bool>& disrespect, vector<bool>& removable){
    bool ans = disrespect[node]; // true->not respect->removable, false->respect->not removable
    for(int &child:edges[node]){
        if(child != parent){
            DFS(child, node, edges, disrespect, removable);
            ans = ans & disrespect[child];
        }
    }
    removable[node] = ans;
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, root; cin>>n;
    vector<vector<int>> edges(n);
    vector<bool> disrespect(n);
    for(int i=0; i<n; i++){
        int x; bool y; cin>>x>>y;
        disrespect[i] = y;
        if(x == -1){
            root = i;
        }else{
            x--;
            edges[x].push_back(i);
            edges[i].push_back(x);
        }
    }

    vector<bool> removable(n);
    DFS(root, -1, edges, disrespect, removable);

    bool flag = false;
    for(int i=0; i<n; i++){
        if(removable[i]){
            flag = true;
            cout<<i+1<<" ";
        }
    }
    if(!flag) cout<<-1;
    cout<<endl;

    return 0;
}