/* https://leetcode.com/problems/jump-game/description/ */

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

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int need=0;
    bool ans=true;
    for(int i=n-1; i>=0; i--){
        if(i==0){
            ans=false;
        }
        need++;
        if(nums[i]>=need){
            need=0;
            ans=true;
        }
    }
    return ans;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<int>v(n);
    for(auto &i:v) cin>>i;

    cout<<canJump(v)<<endl;
    return 0;
}