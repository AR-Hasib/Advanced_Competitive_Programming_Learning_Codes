/* https://codeforces.com/gym/102694/problem/B */

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

void dfs(int curr, int parent, vector<vector<int>>& edges, vector<int>& level){
    if(parent == -1) level[curr] = 0;
    else level[curr] = level[parent] + 1;

    for(int child : edges[curr]){
        if(child != parent) dfs(child, curr, edges, level);
    }
}

pair<int, int> farthestNode(int n, vector<int>& dist){
    int farthest = 0;
    for(int i=0; i<n; i++){
        if(dist[i] > dist[farthest]) farthest = i;
    }
    return {farthest, dist[farthest]};
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<vector<int>> edges(n);
    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    // y and z are the two end node of the diameter. but for this problem,
    // we have to keep in mind that there can be more than one diameter in a tree of same length
    vector<int> distX(n, -1), distY(n, -1);
    int x = 0; // set any node as x
    dfs(x, -1, edges, distX);
    pair<int, int> y = farthestNode(n, distX); // y = (node, distance)

    set<int> allEndOfDiameter;
    // insert all candidate of y
    for(int i=0; i<n; i++) 
        if(distX[i] == y.second) allEndOfDiameter.insert(i);

    dfs(y.first, -1, edges, distY); // z = (node, distance)
    pair<int, int> z = farthestNode(n, distY);
    int diameter = distY[z.first];
    
    // insert all candidate of z
    for(int i=0; i<n; i++) 
        if(distY[i] == z.second) allEndOfDiameter.insert(i);
    
    // printing answer
    for(int i=0; i<n; i++){
        if(allEndOfDiameter.find(i) != allEndOfDiameter.end()) cout<<diameter+1<<endl;
        else cout<<diameter<<endl;
    }
    
    return 0;
}