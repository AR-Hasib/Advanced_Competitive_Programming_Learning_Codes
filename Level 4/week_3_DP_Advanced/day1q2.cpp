/* https://cses.fi/problemset/task/1745 */

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

void f(int idx, int sum, int n, vector<int> &arr, vector<bool> &check, vector<vector<bool>> &dp){
    if(idx == n){
        check[sum] = true;
        return;
    }
    if(dp[idx][sum]) return;

    f(idx+1, sum, n, arr, check, dp);
    f(idx+1, sum+arr[idx], n, arr, check, dp);
    dp[idx][sum] = true;

    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<int> arr(n);
    for(auto &i:arr) cin>>i;

    // worst case mas sum possible 1000*100 = 1e5
    int maxSum = 1e5;
    vector<bool> check(maxSum+1, false);
    check[0] = true;
    
    vector<vector<bool>> dp(n, vector<bool>(1e5, false));
    f(0, 0, n, arr, check, dp);

    int total=0;
    for(int i=1; i<=maxSum; i++)
        if(check[i]) total+=1;
    cout<<total<<endl;
    for(int i=1; i<=maxSum; i++)
        if(check[i]) cout<<i<<" ";

    return 0;
}