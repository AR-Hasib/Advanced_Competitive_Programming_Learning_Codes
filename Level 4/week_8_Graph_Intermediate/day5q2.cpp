/* https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C */

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
    public: 
        vector<int> p, rank, exp;
        UnionFind(int n){
            rank.assign(n, 0); p.assign(n, 0);
            exp.assign(n, 0);
            iota(p.begin(), p.end(), 0);    // parent of each node set to itself
        }

        int findSet(int i){		// return the parent(root) of the set i belongs to
            return (p[i] == i) ? i:findSet(p[i]);
        }
        bool isSameSet(int i, int j){
            return findSet(i) == findSet(j);
        }

        int getExp(int i){
            int ans = 0;
            while(p[i] != i){
                ans += exp[i];
                i = p[i];
            }
            ans += exp[i];
            return ans;
        }

        void addExp(int i, int val){
            int temp = findSet(i);
            exp[temp] += val;
        }

        void unionSet(int i, int j){
            if(!isSameSet(i, j)){
                int x = findSet(i), y = findSet(j);
                if(rank[x] > rank[y]){
                    p[y] = x;
                    exp[y] -= exp[x];
                }else{
                    p[x] = y;
                    exp[x] -= exp[y];
                    if(rank[x] == rank[y]) rank[y]++;
                }
            }
        }
};

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, q; cin>>n>>q;
    UnionFind dsu(n);
    while(q--){
        string s; cin>>s;
        if(s[0] == 'j'){
            int u, v; cin>>u>>v;
            u--, v--;
            dsu.unionSet(u, v);
        }else if(s[0] == 'g'){
            int u; cin>>u; 
            u--;
            cout<<dsu.getExp(u)<<endl;
        }else{
            int u, val; cin>>u>>val;
            u--;
            dsu.addExp(u, val);
        }
    }

    return 0;
}