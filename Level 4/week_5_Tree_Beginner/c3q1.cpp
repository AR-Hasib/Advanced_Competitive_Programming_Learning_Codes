/* https://codeforces.com/contest/979/problem/C */

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

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

int currTime = 0;

void dfs(int currNode, int parent, vector<vector<int>>& edges, vector<int>& subTree, vector<int>& inTime, vector<int>& outTime){
    inTime[currNode] = currTime++;
    subTree[currNode] = 1;

    for(auto &child:edges[currNode]){
        if(child != parent){
            dfs(child, currNode, edges, subTree, inTime, outTime);
            subTree[currNode] += subTree[child];
        }
    }

    outTime[currNode] = currTime++;
}

bool isAncestor(int x, int y, vector<int>& inTime, vector<int>& outTime){ // x is a ancestor of y
    if((inTime[x] < inTime[y]) && (outTime[y] < outTime[x])) return true;
    else return false;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, x, y; cin>>n>>x>>y;
    x--, y--; // 1 -> 0 base 
    vector<vector<int>> edges(n);
    vector<int> subTree(n), inTime(n), outTime(n);
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        a--, b--; // 1 -> 0 base indexing
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(y, -1, edges, subTree, inTime, outTime);

    int ans = n*(n-1);
    int val = n;
    for(int &child:edges[y]){
        if((child==x) || isAncestor(child, x, inTime, outTime)){
            val -= subTree[child];
            break;
        }
    }

    ans -= subTree[x]*val;
    cout<<ans<<endl;

    return 0;
}