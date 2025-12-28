/* https://codeforces.com/problemset/problem/20/C */


///////////////////////////i don't know why this code is getting MLE
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
const int INF = LONG_LONG_MAX;

void djk(int &source, vector<vector<pair<int, int>>> &edges, vector<int> &dist, vector<int> &parent){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});   // distance, node
    dist[source] = 0;
    while(!pq.empty()){
        int currDist = pq.top().first;
        int u = pq.top().second;    // current node
        pq.pop();

        if(dist[u] < currDist) continue;   // already have shorter distance
        for(auto &neigh:edges[u]){
            int v = neigh.first;
            int uvDist = neigh.second+currDist;

            if(uvDist < dist[v]){
                dist[v] = uvDist;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin>>n>>m;
    vector<vector<pair<int, int>>> edges(n);
    for(int i=0; i<m; i++){
        int u, v, x; cin>>u>>v>>x;
        u--, v--;
        edges[u].push_back({v, x});
        edges[v].push_back({u, x});
    }

    int source = 0;
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    djk(source, edges, dist, parent);

    if(dist[n-1] != INF){
        int np = n-1;
        vector<int> ans;
        while(np != -1){
            ans.push_back(np+1);    // 0 -> 1 base
            np = parent[np];
        }
        reverse(all(ans));
        printVector(ans);
    }else cout<<-1<<endl;

    return 0;
}



