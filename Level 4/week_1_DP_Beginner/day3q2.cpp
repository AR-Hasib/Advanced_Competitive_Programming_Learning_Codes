/* https://cses.fi/problemset/task/1746 */ 

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
    
    int n, m; cin>>n>>m;
    vector<int> arr(n);
    for(auto &i:arr) cin>>i;

    vector<vector<int>> dp(n, vector<int>(m+1, 0));
    /* dp[i][k] = the number of ways ith index can be filled where the 
    last element is k */

    if(arr[0]){
        dp[0][arr[0]]=1;
    }else{
        for(int i=1; i<=m; i++) dp[0][i]=1;
    }

    for(int i=1; i<n; i++){
        if(arr[i]==0){
            for(int k=1; k<=m; k++){
                if(k-1 >= 1) dp[i][k] = (dp[i][k] + dp[i-1][k-1])%MOD;
                dp[i][k] = (dp[i][k] + dp[i-1][k])%MOD;
                if(k+1 <= m) dp[i][k] = (dp[i][k] + dp[i-1][k+1])%MOD;
            }
        }else{
            if(arr[i]-1 >= 1) dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][arr[i]-1])%MOD;
            dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][arr[i]])%MOD;
            if(arr[i]+1 <= m) dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][arr[i]+1])%MOD;
        }
    }

    int ans=0;
    for(int i=1; i<=m; i++){
        ans = (ans + dp[n-1][i])%MOD;
    }
    cout<<ans<<endl;

    return 0;
}