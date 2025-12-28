/* https://codeforces.com/problemset/problem/1392/D */

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

int helper(int idx, string &str, vector<vector<vector<int>>> &dp, int sl, int l, int f, int s){
    int n = sz(str);
    if(idx == n-1){
        int changes = 5e5;

        // putting L
        if((sl != 0 || l != 0) && (f != 0 || s != 0) && (l != 0 || f != 0))
            changes = min(changes, str[idx] != 'L' ? 1:0);
        
        // putting R
        if((sl != 1 || l != 1) && (f != 1 || s != 1) && (l != 1 || f != 1))
            changes = min(changes, str[idx] != 'R' ? 1:0);
        
        return changes;
    }

    if(dp[idx][sl][l] != -1) return dp[idx][sl][l];

    int changes = 5e5;

    // putting L
    if(sl != 0 || l != 0)
        changes = min(changes, (str[idx] != 'L' ? 1:0) + helper(idx+1, str, dp, l, 0, f, s));

    // putting R
    if(sl != 1 || l != 1)
        changes = min(changes, (str[idx] != 'R' ? 1:0) + helper(idx+1, str, dp, l, 1, f, s));

    return dp[idx][sl][l] = changes;
}

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    int ans=n;
    for(int i=0; i<=1; i++){
        for(int j=0; j<=1; j++){
            vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));

            int count1 = (i==0 ? s[0] != 'L' : s[0] != 'R');
            int count2 = (j==0 ? s[1] != 'L' : s[1] != 'R');
            ans = min(ans, helper(2, s, dp, i, j, i, j)+count1+count2);
        }
    }
    cout<<ans<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}