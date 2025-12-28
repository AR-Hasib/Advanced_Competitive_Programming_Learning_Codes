/* https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D */

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

struct querry{
    string qsn;
    int node1, node2;
};

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
    
    int n, m, k; cin>>n>>m>>k;
    vector<pair<int, int>> edges(m);
    for(int i=0; i<m; i++) cin>>edges[i].first>>edges[i].second;
    vector<querry> v(k);
    for(int i=0; i<k; i++) cin>>v[i].qsn>>v[i].node1>>v[i].node2;

    reverse(all(v));
    vector<string> ans;
    UnionFind dsu(n);

    for(int i=0; i<k; i++){
        if(v[i].qsn[0] == 'c'){
            dsu.unionSet(v[i].node1-1, v[i].node2-1);
        }else{
            if(dsu.isSameSet(v[i].node1-1, v[i].node2-1)) ans.push_back("YES");
            else ans.push_back("NO");
        }
    }

    reverse(all(ans));
    for(auto i:ans) cout<<i<<endl;
    
    return 0;
}