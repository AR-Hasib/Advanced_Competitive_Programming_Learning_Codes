/* https://cses.fi/problemset/task/1636 */

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

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, sum; cin>>n>>sum;
    vector<int> coins(n);
    for(auto &i:coins) cin>>i;

    // // this solution is ok but it will get runtime error due to a lot memory consumption
    // vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
    // //dp[i][k] is the number of ways to construct sum k where coins before coins[i] are unusable

    // // base case the number of ways to construct sum 0 is 1
    // for(int i=0; i<=n; i++) dp[i][0]=1;

    // for(int i=n-1; i>=0; i--){
    //     for(int k=1; k<=sum; k++){
    //         int skip = dp[i+1][k];
    //         int pick = 0;
    //         if(coins[i]<=k){
    //             pick = dp[i][k-coins[i]];
    //         }
    //         dp[i][k] = (skip+pick)%MOD;
    //     }
    // }
    // cout<<dp[0][sum]<<endl;


    // // 1d dp solution
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;  // Base case: There's one way to form sum 0 (using no coins)

    for (int c : coins) {
        for (int k = c; k <= sum; k++) {
            dp[k] = (dp[k] + dp[k - c]) % MOD;
        }
    }

    cout << dp[sum] << endl;

    return 0;
}