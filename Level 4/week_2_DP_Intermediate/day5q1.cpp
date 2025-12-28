/* https://codeforces.com/contest/1741/problem/E */

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
    int n; cin>>n;
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++) cin>>arr[i];

    vector<bool> dp(n+2, false);
    dp[0]=true;

    for(int i=1; i<=n; i++){
        if(i-arr[i]-1>=0 && dp[i-arr[i]-1]) dp[i] = true;
        if(i+arr[i]<=n && dp[i-1]) dp[i+arr[i]] = true;
    }
    if(dp[n]) yes;
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