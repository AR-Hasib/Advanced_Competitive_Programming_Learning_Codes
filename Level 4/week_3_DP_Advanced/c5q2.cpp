/* https://codeforces.com/contest/1132/problem/F */

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

int f(int l, int r, vector<vector<int>> &dp, string &s){
    if(l > r) return 0;
    if(l == r) return 1;
    if(dp[l][r] != -1) return dp[l][r];

    int ans = 1+f(l+1, r, dp, s);  // removing current
    for(int i=l+1; i<=r; i++){
        if(s[l] == s[i]){
            ans = min(ans, f(l+1, i-1, dp, s) + f(i, r, dp, s));
        }
    }
    return dp[l][r] = ans;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; string s; cin>>n>>s;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout<<f(0, n-1, dp, s)<<endl;
    return 0;
}