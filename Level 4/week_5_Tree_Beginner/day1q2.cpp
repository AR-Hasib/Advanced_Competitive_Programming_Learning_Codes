/* https://codeforces.com/problemset/problem/580/C */

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

int totalRestaurent=0;
bool isLeaf(int vertex, vector<vector<int>>& edges){
    return edges[vertex].size()==1? true:false;
}

void DFS(int node, int parent, int &k, vector<int>& conCatTillCurr, vector<int>& cat, vector<vector<int>>& edges){

    for(int &child:edges[node]){
        if(child != parent){
            // calculate consicutive cat in this child
            if(cat[child]) conCatTillCurr[child] = conCatTillCurr[node]+1;
            else conCatTillCurr[child] = 0;

            if(conCatTillCurr[child] <= k){
                DFS(child, node, k, conCatTillCurr, cat, edges);
            }
        }
    }

    if(isLeaf(node, edges) && (node!=0)) totalRestaurent++;
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k; cin>>n>>k;
    vector<int> cat(n);
    vector<vector<int>> edges(n);
    for(int i=0; i<n; i++) cin>>cat[i];
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    vector<int> conCatTillCurr(n, 0);
    conCatTillCurr[0] = cat[0];
    
    DFS(0, -1, k, conCatTillCurr, cat, edges);
    cout<<totalRestaurent<<endl;

    return 0;
}