/* https://codeforces.com/contest/1799/problem/D1 */

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

int f(int idx, int other, int k, vector<vector<int>> &dp, vector<int> &a, vector<int> &cold, vector<int> &hot){
    if(idx==k) return 0;

    if(dp[idx][other] != -1) return dp[idx][other];
    
    int placeLast = f(idx+1, other, k, dp, a, cold, hot) + (a[idx]==a[idx-1] ? hot[a[idx]]:cold[a[idx]]);
    int placeOther = f(idx+1, a[idx-1], k, dp, a, cold, hot) + (a[idx]==other ? hot[a[idx]]:cold[a[idx]]);
    return dp[idx][other] = min(placeLast, placeOther);
}

void solve(){
    int k, n; cin>>k>>n;
    vector<int> a(k), cold(n+1), hot(n+1);
    for(auto &i:a) cin>>i;
    for(int i=1; i<=n; i++) cin>>cold[i];
    for(int i=1; i<=n; i++) cin>>hot[i];

    vector<vector<int>> dp(k, vector<int>(n+1, -1));

    cout<<cold[a[0]]+f(1, 0, k, dp, a, cold, hot)<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}