/* https://codeforces.com/contest/1000/problem/D */

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
// const ll INF = LLONG_MAX /2;

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(auto &i:a) cin>>i;

    /* dp[i][rem] = number of good subsequence when i am in the ith element and i have
    rem number of element needed to make the previous segment good */
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    dp[n][0] = 1;
    for(int i=n-1; i>=0; i--){
        for(int rem = 0; rem<=n; rem++){
            int curr = 0;
            // skip current element
            curr = (curr + dp[i+1][rem])%MOD;
            // take
            if(rem>0){
                curr = (curr + dp[i+1][rem-1]);
            }else{
                if(a[i]>0 && a[i]<=n) 
                    curr = (curr + dp[i+1][a[i]])%MOD;
            }
            dp[i][rem] = curr;
        }
    }
    cout<<(dp[0][0]-1 +MOD)%MOD<<endl; // -1 because there is a case when i am skipping all the elements
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    solve();
    
    return 0;
}