/* https://codeforces.com/problemset/problem/1245/D */

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

class UnionFind{
    private: vector<int> p, rank;
    public: 
        UnionFind(int n){
            rank.assign(n, 0); p.assign(n, 0);
            iota(p.begin(), p.end(), 0);    // parent of each node set to itself
        }

        int findSet(int i){		// return the parent(root) of the set i belongs to
            return (p[i] == i) ? i:p[i] = findSet(p[i]);
        }
        bool isSameSet(int i, int j){
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j){
            if(!isSameSet(i, j)){
                int x = findSet(i), y = findSet(j);
                if(rank[x] > rank[y]) p[y] = x;
                else{
                    p[x] = y;
                    if(rank[x] == rank[y]) rank[y]++;
                }
            }
        }
};

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    // this problem will be solve in 1 base indexing
    vector<pair<int, int>> city(n+1);
    for(int i=1; i<=n; i++) cin>>city[i].first>>city[i].second;

    vector<int> costStation(n+1), costConnection(n+1);
    for(int i=1; i<=n; i++) cin>>costStation[i];
    for(int i=1; i<=n; i++) cin>>costConnection[i];

    vector<pair<int, pair<int, int>>> edges;    // {cost, {idx of 1st city, idx of 2nd city}}
    // create a dummy node at 0. connection with 0 means building power station
    for(int i=1; i<=n; i++) edges.push_back({costStation[i], {0, i}});

    // calculate the cost for the connections between all the pairs of cities
    for(int u=1; u<=n; u++){
        for(int v=1; v<=n; v++){
            if(u == v) continue;

            int distance = abs(city[u].first-city[v].first) + abs(city[u].second-city[v].second);
            int cost = distance * (costConnection[u]+costConnection[v]);
            edges.push_back({cost, {u, v}});
        }
    }

    // implement kruskal's algo and find the minimum spanning tree
    vector<int> stations;
    vector<pair<int, int>> connections;
    int totalCost = 0;
    UnionFind dsu(n+1);
    sort(edges.begin(), edges.end(), [&](auto a, auto b){
        return a.first < b.first;
    });

    for(auto &[cost, uv]:edges){
        auto [u, v] = uv;
        if(dsu.isSameSet(u, v)) continue;

        dsu.unionSet(u, v);
        totalCost += cost;
        if(u == 0) stations.push_back(v);
        else connections.push_back({u, v});
    }

    // mst will ensure that at least one vertex will be connected with 0 (has powerPlant)

    cout<<totalCost<<endl;
    cout<<stations.size()<<endl;
    printVector(stations);
    cout<<connections.size()<<endl;
    for(auto [u, v]:connections) cout<<u<<" "<<v<<endl;

    return 0;
}