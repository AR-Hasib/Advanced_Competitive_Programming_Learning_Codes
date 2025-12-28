/* https://cses.fi/problemset/task/1195 */

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
const int INF = LLONG_MAX /4;

void djk(int source, vector<vector<pair<int, int>>> &edges, vector<int> &dist){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});   // distance, node
    dist[source] = 0;
    while(!pq.empty()){
        int currDist = pq.top().first;
        int u = pq.top().second;    // current node
        pq.pop();

        if(dist[u] < currDist) continue;   // already have shorter distance,
        for(auto &neigh:edges[u]){
            int v = neigh.first;
            int uvDist = neigh.second+currDist;

            if(uvDist < dist[v]){
                dist[v] = uvDist;
                pq.push({dist[v], v});
            }
        }
    }
}

struct customA{
    int one, two, price;
};

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin>>n>>m;
    vector<vector<pair<int, int>>> edges1(n), edges2(n);   // ith node -> 2nd node, price
    vector<customA> all;    // keep for easy calculation, can be skipped
    while(m--){
        int u, v, x; cin>>u>>v>>x;
        u--, v--;
        edges1[u].push_back({v, x});
        edges2[v].push_back({u, x});
        all.push_back({u, v, x});
    }

    vector<int> distFrom1(n, INF), distFromN(n, INF);
    djk(0, edges1, distFrom1);
    djk(n-1, edges2, distFromN);

    int minCost = INF;
    for(auto &i : all){
        int currCost = i.price/2 + distFrom1[i.one] + distFromN[i.two];
        minCost = min(minCost, currCost);
    }
    cout<<minCost;

    return 0;
}