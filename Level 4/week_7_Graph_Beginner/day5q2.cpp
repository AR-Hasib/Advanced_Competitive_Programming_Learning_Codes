/* https://codeforces.com/contest/1365/problem/D */

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

void solve(){
    int n, m; cin>>n>>m;
    VV(char) grid(n, vector<char>(m));
    int goodCount = 0;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0; j<m; j++){
            grid[i][j] = s[j];
            if(grid[i][j] == 'G') goodCount++;
        }
    }

    if(goodCount == 0){
        yes; //if there is no G, then it will be always yes because we can block the escape point.
        return;
    }

    /* if some G exist, at first we will try to block all 4 side (if there is nothing '.') of each B. 
    then we will run a dfs from escape point. if we visit no B, and all G then it will be yes else no*/

    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, 1, -1};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 'B'){
                for(int k=0; k<4; k++){
                    int newX = i+dx[k], newY = j+dy[k];
                    if(newX>=0 && newY>=0 && newX<n && newY<m){
                        if(newX==n-1 && newY==m-1){
                            no; // if a B is just beside the escape point, we can't block him
                            return;
                        }
                        if(grid[newX][newY] == 'G'){
                            no; //if there is a G beside any B then ans will be no (that B will follow the path of that G)
                            return;
                        }else if(grid[newX][newY] == '.') grid[newX][newY] = '#';
                    }
                }
            }
        }
    }

    VV(bool) visited(n, vector<bool>(m, false));
    int countG = 0, countB = 0;
    auto dfs = [&] (auto &&dfs, int x, int y)->void{
        visited[x][y] = true;
        if(grid[x][y] == 'G') countG++;
        if(grid[x][y] == 'B') countB++;
        for(int k=0; k<4; k++){
            int newX = x+dx[k], newY = y+dy[k];
            if(newX>=0 && newY>=0 && newX<n && newY<m){
                if(!visited[newX][newY] && ((grid[newX][newY]=='.' ) || (grid[newX][newY]=='G'))) dfs(dfs, newX, newY);
            }
        }
    };
    visited[n-1][m-1] = true;
    dfs(dfs, n-1, m-1);

    // cout<<" "<<countG<<" "<<goodCount<<" "<<countB<<" ";
    if(countB){
        no;
        return;
    }
    if(countG == goodCount) yes;
    else no;

    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}