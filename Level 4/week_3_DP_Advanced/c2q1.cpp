/* https://atcoder.jp/contests/dp/tasks/dp_o */

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

int f(int idx, int mask, vector<vector<int>> &dp, vector<vector<int>> &a, int n){
    if(idx==n) return 1;
    if(dp[idx][mask] != -1) return dp[idx][mask];

    int ways=0;
    for(int i=0; i<n; i++){
        if(((1<<i)& mask) == 0 && a[idx][i]){
            ways = (ways + f(idx+1, mask | 1<<i, dp, a, n))%MOD;
        }
    }

    return dp[idx][mask] = ways;
}

int opF(int mask, vector<int> &dp, vector<vector<int>> &a, int n){
    int idx = __builtin_popcount(mask);
    if(idx==n) return 1;
    if(dp[mask] != -1) return dp[mask];

    int ways=0;
    for(int i=0; i<n; i++){
        if(((1<<i)& mask) == 0 && a[idx][i]){
            ways = (ways + opF(mask | (1<<i), dp, a, n))%MOD;
        }
    }

    return dp[mask] = ways;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin>>a[i][j];
    }

    // without optimization
    // vector<vector<int>> dp(n, vector<int>(1<<n, -1));
    // cout<<f(0, 0, dp, a, n)<<endl;

    // with optimization
    vector<int> dp(1<<n, -1);
    cout<<opF(0, dp, a, n)<<endl;

    return 0;
}