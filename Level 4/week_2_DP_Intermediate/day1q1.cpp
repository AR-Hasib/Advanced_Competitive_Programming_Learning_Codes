/* https://atcoder.jp/contests/abc222/tasks/abc222_d */

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

const int MOD = 998244353;

void solve(){
    int n; cin>>n;
    vector<int> a(n+1), b(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];
    int mx = b[n];

    vector<vector<int>> dp(n+1, vector<int>(mx+1, 0)), sum(n+1, vector<int>(mx+1, 0));
    dp[0][0] = 0;
    for(int i=0; i<=mx; i++) sum[0][i]=1;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=mx; j++){
            if(j>=a[i] && j<=b[i]){
                dp[i][j] = sum[i-1][j];
            }
            sum[i][j] = ((j>0 ? sum[i][j-1]:0) + dp[i][j])%MOD;
        }
    }
    cout<<sum[n][mx]<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}