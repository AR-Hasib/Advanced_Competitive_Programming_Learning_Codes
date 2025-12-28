/* https://codeforces.com/problemset/problem/1513/C */

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

const int MOD = 1e9 + 7;
const int Max = 2e5 + 5;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);

    vector<vector<int>> dp(Max, vector<int>(10, 0));

    for(int i=0; i<=9; i++){
        dp[0][i] = 1;
    }

    for(int i=1; i<Max; i++){
        for(int j=0; j<9; j++){
            dp[i][j] = dp[i-1][j+1];
        }
        dp[i][9] = (dp[i-1][0]+dp[i-1][1])%MOD;
    }
    
    int tc; cin>>tc;
    while(tc--){
        string n;
        int m; cin>>n>>m;

        int ans=0;
        for(auto i:n){
            ans = (ans + dp[m][i-'0'])%MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}