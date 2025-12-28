/* https://codeforces.com/problemset/problem/1036/C */

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
const int INF = LLONG_MAX /2;

int f(int index, int tight, int nonZero, string &s, int n, vector<vector<vector<int>>> &dp){
    if(nonZero > 3) return 0;
    if(index == n) return 1;
    if(dp[index][tight][nonZero] != -1) return dp[index][tight][nonZero];

    int ans = 0;
    int range = tight ? s[index]-'0' : 9;
    for(int i=0; i<=range; i++){
        ans = (ans + f(index+1, tight && (s[index]-'0' == i), nonZero + (i != 0), s, n, dp));
    } 
    return dp[index][tight][nonZero] = ans;
}

void solve(){
    int left, right; cin>>left>>right;
    left--; 
    string l = to_string(left), r = to_string(right);
    
    vector<vector<vector<int>>> dp(20, vector<vector<int>>(2, vector<int>(4, -1)));

    int rightTotal = f(0, 1, 0, r, sz(r), dp);
    for(auto &i:dp){
        for(auto &j:i){
            for(auto &k:j) k=-1; 
        }
    }
    int leftTotal = f(0, 1, 0, l, sz(l), dp);
    cout<<rightTotal-leftTotal<<endl;
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