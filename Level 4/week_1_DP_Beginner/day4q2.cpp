/* https://codeforces.com/problemset/problem/166/E */

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
// const ll INF = LLONG_MAX /2;

void solve(){
    int n; cin>>n;
    vector<vector<int>> dp(2, vector<int>(n+1));

    // dp[1][x] here 1 is consider as top vertics D, no of way to reach vertics D in x steps
    // dp[0][x] here 0 is consider as any bottom vertics
    dp[0][0] = 0;
    dp[1][0] = 1;

    for(int i=1; i<=n; i++){
        dp[1][i] = (3*dp[0][i-1])%MOD;
        dp[0][i] = (2*dp[0][i-1] + dp[1][i-1])%MOD;
    }
    cout<<dp[1][n];
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}

