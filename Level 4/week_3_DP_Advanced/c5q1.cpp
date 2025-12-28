/* https://codeforces.com/contest/1625/problem/C */

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

int f(int index, int k, int n, vector<int> &points, vector<int> &speed, vector<vector<int>> &dp){
    if(index == n) return 0;
    if(dp[index][k] != -1) return dp[index][k];

    int ans = INT_MAX;
    for(int i=index+1; (i<n+1) && (i-index-1 <= k); i++){
        // (i-index-1) is the count of how many we are skipping, so it is 0 when we are not skipping
        ans = min(ans, f(i, k-(i-index-1), n, points, speed, dp) + (points[i]-points[index])*speed[index]);
    }
    return dp[index][k] = ans;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, l, k; cin>>n>>l>>k;
    vector<int> points(n+1), speed(n+1);
    points[n] = l;
    for(int i=0; i<n; i++) cin>>points[i];
    for(int i=0; i<n; i++) cin>>speed[i];

    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    cout<<f(0, k, n, points, speed, dp);

    return 0;
}