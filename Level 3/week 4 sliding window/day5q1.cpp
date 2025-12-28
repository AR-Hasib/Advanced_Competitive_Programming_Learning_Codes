/* https://leetcode.com/problems/k-radius-subarray-averages/description/ */

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n, -1);
        
        int window=2*k+1;
        if(n<window) return ans;

        long long sum=0;
        for(int i=0; i<window-1; i++) sum+=nums[i];

        for(int i=k; i<n-k; i++){
            sum+=nums[i+k];
            ans[i]= sum/window;
            sum-=nums[i-k];
        }
        return ans;
    }
};