/* https://codeforces.com/gym/102694/problem/D */

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

struct Tree {
    int n, LOG;
    vector<vector<pair<int, int>>> adj;
    vector<vector<int>> mini;
    vector<vector<int>> ancestor;
    vector<int> level;

    Tree(int _n) {
        n = _n;
        LOG = log2(n) + 1;
        adj.resize(n + 1);
        ancestor.assign(n + 1, vector<int>(LOG, 0));
        mini.assign(n + 1, vector<int>(LOG, INT_MAX));
        level.resize(n + 1, 0);
    }

    void addEdge(int u, int v, int x) {
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
    }

    void build(int root = 1) {
        dfs(root, 0);
        buildAncestor();
        computeLevel(root, 0);
    }

    void dfs(int node, int parent) {
        ancestor[node][0] = parent;
        for (auto &child : adj[node]) {
            if (child.first != parent) {
                mini[child.first][0] = child.second;
                dfs(child.first, node);
            }
        }
    }

    void buildAncestor() {
        for (int i = 1; i < LOG; i++) {
            for (int node = 1; node <= n; node++) {
                int mid = ancestor[node][i - 1];
                ancestor[node][i] = ancestor[mid][i - 1];
                mini[node][i] = min(mini[node][i-1], mini[mid][i-1]);
            }
        }
    }

    void computeLevel(int node, int parent) {
        for (auto &child : adj[node]) {
            if (child.first != parent) {
                level[child.first] = level[node] + 1;
                computeLevel(child.first, node);
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i < LOG; i++) {
            if (k & (1 << i)) {
                node = ancestor[node][i];
            }
        }
        return node;
    }

    int getMin_Till_KthAncestor(int node, int k){
        int minEdges = INT_MAX;
        for (int i = 0; i < LOG; i++) {
            if (k & (1 << i)) {
                minEdges = min(minEdges, mini[node][i]);
                node = ancestor[node][i];
            }
        }
        return minEdges;
    }

    int getLCA(int u, int v) {
        if (level[u] < level[v]) swap(u, v);
        u = getKthAncestor(u, level[u] - level[v]);
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; i--) {
            if (ancestor[u][i] != ancestor[v][i]) {
                u = ancestor[u][i];
                v = ancestor[v][i];
            }
        }
        return ancestor[u][0];
    }

    int getDistance(int u, int v) {
        int lca = getLCA(u, v);
        return level[u] + level[v] - 2 * level[lca];
    }

    int getLevel(int u){
        return level[u];
    }
};

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin>>n>>m;
    Tree tree(n);
    for(int i=1; i<=m; i++){
        int u, v, x; cin>>u>>v>>x;
        tree.addEdge(u, v, x);
    }
    tree.build();

    int q; cin>>q;
    while(q--){
        int u, v; cin>>u>>v;
        int lca = tree.getLCA(u, v);
        int du = tree.getLevel(u)-tree.getLevel(lca);
        int dv = tree.getLevel(v)-tree.getLevel(lca);

        // cout<<"lca: "<<lca<<"du dv: "<<du<<" "<<dv<<endl;
        int minAns = INT_MAX;
        if (u != lca) minAns = min(minAns, tree.getMin_Till_KthAncestor(u, du));
        if (v != lca) minAns = min(minAns, tree.getMin_Till_KthAncestor(v, dv));
        cout<<minAns<<endl;
    }
    
    return 0;
}