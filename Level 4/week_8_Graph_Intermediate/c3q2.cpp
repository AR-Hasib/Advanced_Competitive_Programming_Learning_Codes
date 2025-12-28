/* https://codeforces.com/problemset/problem/1609/D */

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
    private: vector<int> p, size;
    public: 
        UnionFind(int n){
            size.assign(n, 1); p.assign(n, 0);
            iota(p.begin(), p.end(), 0);    // parent of each node set to itself
        }

        int findSet(int i){     // return the parent(root) of the set i belongs to
            return (p[i] == i) ? i:p[i] = findSet(p[i]);
        }
        bool isSameSet(int i, int j){
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j){
            if(!isSameSet(i, j)){
                int x = findSet(i), y = findSet(j);
                if(size[x] < size[y]) swap(x, y);
                p[y] = x;
                size[x] += size[y];
            }
        }

        int getSize(int i) {
            return size[findSet(i)];
        }
};

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin>>n>>m;
    UnionFind dsu(n);

    int freeEdge = 0;
    while(m--){
        int u, v; cin>>u>>v;
        u--, v--;

        // if they are in the same connected component we will have an extra freeEdge
        if(dsu.isSameSet(u, v)) freeEdge++;
        else dsu.unionSet(u, v);

        // now we will find freeEdge+1 bigger comp, and the sum of their size -1 will be the ans
        vector<int> temp;
        set<int> taken; // keep track of the components size already taken, ensure no duplicte
        for(int i=0; i<n; i++){
            int par = dsu.findSet(i);
            if(!taken.count(par)){
                temp.push_back(dsu.getSize(par));
                taken.insert(par);
            } 
        }
        sort(temp.rbegin(), temp.rend());

        int ans = 0;
        for(int i=0; i<temp.size(); i++){
            ans += temp[i];
            if(i==freeEdge) break;
        }
        cout<<ans-1<<endl;
    }
    
    return 0;
}

