/* https://codeforces.com/problemset/problem/1133/E */

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

int f(int index, int teamFormed, vector<vector<int>> &dp, vector<int> &idx, int n, int k){
    if(index == n || teamFormed == k) return 0;
    if(dp[index][teamFormed] != -1) return dp[index][teamFormed];

    return dp[index][teamFormed] = max(f(index+1, teamFormed, dp, idx, n, k), 
            (idx[index] - index + 1) + f(idx[index]+1, teamFormed+1, dp, idx, n, k));
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k; cin>>n>>k;
    vector<int> arr(n);
    for(auto &i:arr) cin>>i;
    sort(all(arr));

    // idx(i) = the last element we can take if we choose arr[i] as
    // our smallest element in the current team
    vector<int> idx(n);
    for(int i=0, j=0; i<n; i++){
        while(j<n && (arr[j]-arr[i] <= 5)) j++;
        idx[i] = j-1;
    }

    vector<vector<int>> dp(n, vector<int>(k, -1));
    cout<<f(0, 0, dp, idx, n, k);

    return 0;
}