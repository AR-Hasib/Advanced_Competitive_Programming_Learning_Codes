/* https://cses.fi/problemset/task/1744 */

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

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));
    /* dp[i][j] = min number of cut to make a block of i*j into squares */

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==j){
                dp[i][j]=0;
                continue;
            }

            // horizontal cuts
            for(int h=1; h<i; h++){
                dp[i][j] = min(dp[i][j], 1+dp[h][j]+dp[i-h][j]);
            }

            // vertical cuts
            for(int v=1; v<j; v++){
                dp[i][j] = min(dp[i][j], 1+dp[i][v]+dp[i][j-v]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}