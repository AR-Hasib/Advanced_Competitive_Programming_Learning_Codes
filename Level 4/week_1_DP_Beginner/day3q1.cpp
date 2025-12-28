/* https://codeforces.com/problemset/problem/1350/B */

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

int f(int idx, vector<int> &dp, vector<int> arr, int n){
    if(idx > n) return 0;

    if(dp[idx] != -1) return dp[idx];

    int count=0;
    for(int i=idx*2; i<=n; i+=idx){
        if(arr[i]>arr[idx]){
            count = max(count, 1+f(i, dp, arr, n));
        }
    }
    return dp[idx]=count;
}

void solve(){
    int n; cin>>n;
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++) cin>>arr[i];

    vector<int> dp(n+1, -1);
    int maxi = 1;
    for(int i=1; i<=n; i++){
        maxi = max(maxi, 1+f(i, dp, arr, n));
    }
    cout<<maxi<<endl;
    return;
}

void tab(){
    int n;
    cin >> n;
    
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<int> dp(n + 1, 1);  // Initialize all values with 1 (each number alone is a sequence)

    int maxi = 1;
    
    for (int idx = n; idx >= 1; idx--) { // Start from n and move to 1 (bottom-up)
        for (int multiple = idx * 2; multiple <= n; multiple += idx) {
            if (arr[multiple] > arr[idx]) {
                dp[idx] = max(dp[idx], 1 + dp[multiple]); // Update dp[idx] if a valid sequence is found
            }
        }
        maxi = max(maxi, dp[idx]); // Track the maximum length
    }

    cout << maxi << endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        // solve();    // recursive
        tab();  // tabulation
    }
    return 0;
}