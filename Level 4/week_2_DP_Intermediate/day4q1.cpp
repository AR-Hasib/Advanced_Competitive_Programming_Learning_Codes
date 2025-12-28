/* https://codeforces.com/contest/1517/problem/D */

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

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m, steps; cin>>n>>m>>steps;
    vector<vector<int>> horizontal(n, vector<int>(m-1)), vertical(n-1, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m-1; j++) cin>>horizontal[i][j];
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m; j++) cin>>vertical[i][j];
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(steps+1)));

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {-1, 1, 0, 0};

    for(int k=0; k<steps+1; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(k&1) dp[i][j][k] = -1;
                else{
                    if(k==0) dp[i][j][k] = 0;
                    else{
                        dp[i][j][k] = 2e9;
                        for(int e=0; e<4; e++){
                            int newI = i+dx[e], newJ = j+dy[e];
                            if(0<=newI && newI<n && 0<=newJ && newJ<m){
                                int weight = 0;
                                if(newI != i) weight = vertical[min(newI, i)][j];
                                else weight = horizontal[i][min(newJ, j)];
                                dp[i][j][k] = min(dp[i][j][k], dp[newI][newJ][k-2]+(2*weight));
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<dp[i][j][steps]<<" ";
        }
        cout<<endl;
    }

    return 0;
}