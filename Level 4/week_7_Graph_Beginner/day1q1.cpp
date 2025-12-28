/* https://codeforces.com/problemset/problem/510/B */

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
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
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
    
    int n, m; cin>>n>>m;
    vector<string> grid(n);
    for(int i=0; i<n; i++) cin>>grid[i];

    VV(bool) visited(n, vector<bool>(m, false));
    bool cycle = false;
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, 1, -1};

    auto dfs = [&] (auto &&dfs, int i, int j, char color, int parentX, int parentY) -> void{
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(grid[i][j] != color) return;
        if(visited[i][j]){
            cycle = true;
            return;
        }

        visited[i][j] = true;
        for(int a=0; a<4; a++){
            int nextX = i + dx[a];
            int nextY = j + dy[a];
            if(nextX == parentX && nextY == parentY) continue;
            
            dfs(dfs, nextX, nextY, color, i, j);
        }
    };

    for(int k=0; k<n; k++){
        for(int l=0; l<m; l++){
            if(cycle) break;
            if(!visited[k][l]) dfs(dfs, k, l, grid[k][l], -1, -1); 
        }
    }

    if(cycle) yes;
    else no;

    return 0;
}