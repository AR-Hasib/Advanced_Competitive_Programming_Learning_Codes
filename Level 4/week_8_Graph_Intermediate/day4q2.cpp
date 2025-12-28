/* https://codeforces.com/problemset/problem/1559/D1 */

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
    
    int n, a, b; cin>>n>>a>>b;
    UnionFind dsu1(n);
    UnionFind dsu2(n);
    while(a--){
        int u, v; cin>>u>>v;
        u--, v--;
        dsu1.unionSet(u, v);
    }
    while(b--){
        int u, v; cin>>u>>v;
        u--, v--;
        dsu2.unionSet(u, v);
    }

    vector<pair<int, int>> ans;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;
            if(dsu1.isSameSet(i, j) || dsu2.isSameSet(i, j)) continue;

            dsu1.unionSet(i, j); dsu2.unionSet(i, j);
            ans.push_back({i, j});
        }
    }
    
    cout<<ans.size()<<endl;
    for(auto i:ans) cout<<i.first+1<<" "<<i.second+1<<endl;

    return 0;
}