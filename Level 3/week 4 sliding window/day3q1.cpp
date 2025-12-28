/* https://leetcode.com/problems/sliding-window-maximum/ */
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

// solution start
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>box;

        for(int i=0; i<nums.size(); i++){
            if(i-k>=0 && !box.empty() && box.back()==nums[i-k]) box.pop_back(); // we have consider k subarray
            while((!box.empty()) && box.front()<nums[i]) box.pop_front();       // we have to check if anything less than the current is in the queue or not.
            box.push_front(nums[i]);

            if(i>=k-1) ans.push_back(box.back());
        }
    return ans;
}
// solution end

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k; cin>>n>>k;
    vector<int>nums(n);
    for(auto &i:nums) cin>>i;

    vector<int> ans=maxSlidingWindow(nums, k);
    for(auto i:ans) cout<<i<<" ";

    return 0;
}

    