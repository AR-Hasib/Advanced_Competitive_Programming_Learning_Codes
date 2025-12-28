/* https://codeforces.com/problemset/problem/763/A */

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

bool DFS(int node, int parent, vector<int>& c, vector<vector<int>>& edges){
    bool ans = true;
    for(int &child:edges[node]){
        if(child != parent){
            if(c[node] != c[child]){
                ans = false;
                return false;
            }
            ans = ans & DFS(child, node, c, edges);
        }
    }
    return ans;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<vector<int>> edges(n);
    vector<int> c(n);
    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    bool allSame = true;
    for(int i=0; i<n; i++){
        cin>>c[i];
        if(i>0){
            if(c[i]!=c[i-1]) allSame = false;
        } 
    }
    // all the vertex are of same color, we can chose anyone as root
    if(allSame){
        yes;
        cout<<1<<endl;
        return 0;
    }

    // we chose u and v where the color differ and try to make any one of them root
    int canU, canV;
    for(int i=0; i<n; i++){
        for(auto &child:edges[i]){
            if(c[i] != c[child]){
                canU = i;
                canV = child;
                break;
            }
        }
    }

    bool ansU = true;
    for(auto &child:edges[canU]){
        ansU = ansU & DFS(child, canU, c, edges);
        
    }
    if(ansU){
        yes;
        cout<<canU+1<<endl;
    }else{
        bool ansV = true;
        for(auto &child:edges[canV]){
            ansV = ansV & DFS(child, canV, c, edges);
        }
        if(ansV){
            yes;
            cout<<canV+1<<endl;
        }else no;
    }
    
    return 0;
}