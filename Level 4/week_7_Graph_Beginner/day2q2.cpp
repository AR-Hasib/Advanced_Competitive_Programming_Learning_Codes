/* https://codeforces.com/problemset/problem/986/A */

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
    
    int n, numberOfEdges, totalType, typesNeededForFair; 
    cin>>n>>numberOfEdges>>totalType>>typesNeededForFair;
    VV(int) goods(totalType);   // goods[i] = nodes that produce goods type i
    for(int i=0; i<n; i++){
        int a; cin>>a;
        a--;
        goods[a].push_back(i);
    }

    VV(int) edges(n);
    for(int i=1; i<=numberOfEdges; i++){
        int u, v; cin>>u>>v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    VV(int) minCost(n, vector<int>(totalType));
    for(int goodsType=0; goodsType<totalType; goodsType++){
        // we will go through all types of goods one by one and try to find the minimum cost to take it to all other nodes
        vector<int> cost(n, INT_MAX);
        queue<int> q;

        for(int node:goods[goodsType]){
            // push all the nodes which produce current goods type
            q.push(node);
            cost[node] = 0;
        }
        // bfs ensure minimum cost (shortest path)
        while(!q.empty()){
            int curr = q.front(); q.pop();
            for(int neigh:edges[curr]){
                if(cost[neigh] > cost[curr]+1){
                    cost[neigh] = cost[curr]+1;
                    q.push(neigh);
                }
            }
        }
        for(int i=0; i<n; i++) minCost[i][goodsType] = cost[i];
    }

    for(int node=0; node<n; node++){
        sort(all(minCost[node]));
        int sum = 0;
        for(int j=0; j<typesNeededForFair; j++){
            sum += minCost[node][j];
        }
        cout<<sum<<" ";
    }

    return 0;
}