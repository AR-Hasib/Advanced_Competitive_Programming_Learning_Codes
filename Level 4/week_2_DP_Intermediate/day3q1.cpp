/* https://codeforces.com/problemset/problem/1324/E */

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

const int INF = 1e9;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, h, l, r; cin>>n>>h>>l>>r;
    vector<int> v(n+1);
    for(int i=1; i<=n; i++) cin>>v[i];

    // // without space optimization
    // vector<vector<int>> dp(n+1, vector<int>(h, -INF));
    // // dp[i][j] = number of good sleep when sleeping on jth hour in ith sleep

    // dp[0][0] = 0;

    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<h; j++){
    //         dp[i][j] = max(dp[i-1][(j-v[i]+1+h)%h], dp[i-1][(j-v[i]+h)%h]);
    //         if(l<=j && j<=r && dp[i][j]!=-INF) dp[i][j]++;
    //     }
    // }
    // int ans=0;
    // for(int i=0; i<h; i++) ans=max(ans, dp[n][i]);
    // cout<<ans<<endl;

    // with space optimization
    vector<int> curr(h, -INF), pre(h, -INF);
    pre[0]=0;

    for(int i=1; i<=n; i++){
        for(int j=0; j<h; j++){
            curr[j] = max(pre[(j-v[i]+1+h)%h], pre[(j-v[i]+h)%h]);
            if(l<=j && j<=r && curr[j]!=-INF) curr[j]++;
        }
        pre=curr;
    }
    int ans=0;
    for(int i=0; i<h; i++) ans=max(ans, curr[i]);
    cout<<ans<<endl;

    return 0;
}