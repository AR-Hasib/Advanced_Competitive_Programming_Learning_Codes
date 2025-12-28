/* https://codeforces.com/problemset/problem/474/D */

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

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k; cin>>n>>k;
    vector<int> dp(1e5+5, 0);
    dp[0]=1;

    for(int i=1; i<1e5+5; i++){
        dp[i] += dp[i-1];
        if(i-k >= 0) dp[i] = (dp[i]+dp[i-k])%MOD;
    }

    // using prefix sum technnique
    for(int i=1; i<1e5+5; i++){
        dp[i] = (dp[i]+dp[i-1])%MOD;
    }

    while(n--){
        int x, y; cin>>x>>y;
        cout<<(dp[y]-dp[x-1]+MOD)%MOD<<endl;
    }

    return 0;
}