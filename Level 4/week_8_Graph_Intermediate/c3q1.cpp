/* https://codeforces.com/contest/2014/problem/E */

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

const int INF = LLONG_MAX /2;

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

void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<pair<int, int>>> edges(n+n);
    vector<int> horse;
    while(k--){
        int x; cin>>x;
        horse.push_back(x-1);
    }
    while(m--){
        int u, v, cost;
        cin>>u>>v>>cost;
        u--, v--;
        edges[u].push_back({v, cost});
        edges[v].push_back({u, cost});

        edges[n+u].push_back({n+v, cost/2});
        edges[n+v].push_back({n+u, cost/2});
    }
    for(int i=0; i<n; i++){
        edges[n+i].push_back({i, 0});
    }
    for(int i:horse){
        edges[i].push_back({i+n, 0});
    }

    vector<int> distA(n+n, INF), distN(n+n, INF);
    djk(0, edges, distA);
    djk(n-1, edges, distN);

    int ans = INF;
    for(int i=0; i<n+n; i++){
        ans = min(ans, max(distA[i], distN[i]));
    }

    if(ans == INF) cout<<-1<<endl;
    else cout<<ans<<endl;

    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}