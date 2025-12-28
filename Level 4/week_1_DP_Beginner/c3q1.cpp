/* https://codeforces.com/problemset/problem/1881/E */

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

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n; cin>>n;
    vector<int>arr(n);
    for(auto &i:arr) cin>>i;

    vector<int>dp(n);
    for(int i=n-1; i>=0; i--){
        int pick=0;
        if(arr[i]+i <= n-1){
            pick += arr[i]+1;
            if(arr[i]+i+1 <= n-1){
                pick += dp[arr[i]+i+1];
            }
        }

        int skip=0;
        if(i+1 <= n-1){
            skip += dp[i+1];
        }

        dp[i] = max(skip, pick);
    }
    
    cout<<n-dp[0]<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}