/* https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/description/ */

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

// const ll MOD = 1e9 + 7;
const int INF = INT_MAX /2;

int f(int index, int mask, int n, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp){
    if(index == n){
        return 0;
    }

    if(dp[index][mask] != -1) return dp[index][mask];

    int ans = INT_MAX/2;
    for(int i=0; i<n; i++){
        if((mask & (1<<i)) == 0){
            ans = min(ans, (nums1[index] ^ nums2[i]) + f(index+1, mask | (1<<i), n, nums1, nums2, dp));
        }
    }
    return dp[index][mask] = ans;
}

int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<vector<int>> dp(n, vector<int>((1<<n)+1, -1));
    return f(0, 0, n, nums1, nums2, dp);
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<int> nums1(n), nums2(n);
    for(auto &i:nums1) cin>>i;
    for(auto &i:nums2) cin>>i;

    cout<<minimumXORSum(nums1, nums2);
    return 0;
}