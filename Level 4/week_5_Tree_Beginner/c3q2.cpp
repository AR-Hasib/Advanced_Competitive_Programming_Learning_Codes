/* https://codeforces.com/contest/1946/problem/C */

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

void possibleDFS(int node, int parent, int currSize, int &totalSegment, vector<vector<int>>& edges, vector<int>& subTree){
    subTree[node] = 1;
    for(auto &child : edges[node]){
        if(child != parent){
            possibleDFS(child, node, currSize, totalSegment, edges, subTree);
            subTree[node] += subTree[child];
        }
    }

    if(subTree[node] >= currSize){
        totalSegment++;
        subTree[node] = 0;
    }
    if(node == 0) return;  
}

int binary(int n, int k, vector<vector<int>>& edges, vector<int>& subTree){
    int left = 1, right = n;
    int ans = 1;
    while(left<=right){
        int mid = (left+right)/2;

        int totalSegment = 0;
        possibleDFS(0, -1, mid, totalSegment, edges, subTree);
        if(totalSegment >= k){
            ans = mid;
            left = mid+1;
        }else right = mid-1;
    }
    return ans;
}

void solve(){
    int n, k; cin>>n>>k;
    vector<vector<int>> edges(n);
    vector<int> subTree(n);
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        a--, b--; // 1 -> 0 base indexing
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    cout<<binary(n, k+1, edges, subTree)<<endl;
    // i am passing k+1 because if i remove k edges then i can say i create k+1 segment
    // so my target is now to make k+1 segment of most number of nodes possible
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}