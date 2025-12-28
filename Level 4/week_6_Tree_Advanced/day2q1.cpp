/* https://cses.fi/problemset/task/1135 */

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

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

struct Tree {
    int n, LOG;
    vector<vector<int>> adj;
    vector<vector<int>> ancestor;
    vector<int> level;

    Tree(int _n) {
        n = _n;
        LOG = log2(n) + 1;
        adj.resize(n + 1);
        ancestor.assign(n + 1, vector<int>(LOG, 0));
        level.resize(n + 1, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void build(int root = 1) {
        dfs(root, 0);
        buildAncestor();
        computeLevel(root, 0);
    }

    void dfs(int node, int parent) {
        ancestor[node][0] = parent;
        for (int child : adj[node]) {
            if (child != parent) {
                dfs(child, node);
            }
        }
    }

    void buildAncestor() {
        for (int i = 1; i < LOG; i++) {
            for (int node = 1; node <= n; node++) {
                int mid = ancestor[node][i - 1];
                ancestor[node][i] = ancestor[mid][i - 1];
            }
        }
    }

    void computeLevel(int node, int parent) {
        for (int child : adj[node]) {
            if (child != parent) {
                level[child] = level[node] + 1;
                computeLevel(child, node);
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
};

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, q; cin>>n>>q;
    Tree tree(n);
    for(int i=2; i<=n; i++){
        int u, v; cin>>u>>v;
        tree.addEdge(u, v);
    }
    tree.build(1);

    while(q--){
        int u, v; cin>>u>>v;
        cout<<tree.getDistance(u, v)<<endl;
    }
    
    return 0;
}