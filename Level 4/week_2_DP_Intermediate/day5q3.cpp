/* https://codeforces.com/contest/1509/problem/C */

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

void solve(){
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    a[0]=0;
    sort(a.begin(), a.end());

    vector<vector<int>> dp(n+2, vector<int>(n+1, 1e15));
    // dp[i][j] = min difference sum from ai..to..aj

    for(int i=n; i>=1; i--){
        for(int j=i; j<=n; j++){
            if(i==j) dp[i][j] = 0;
            else{
                dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + a[j]-a[i];
            }
        }
    }
    cout<<dp[1][n]<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}