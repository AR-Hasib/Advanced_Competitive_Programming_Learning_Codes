/* https://leetcode.com/problems/count-number-of-nice-subarrays/description/ */

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n= nums.size();
        for(int i=0; i<n; i++) nums[i]=nums[i]%2;

        map<int, int>mp;
        int ans=0;
        for(int i=0; i<n; i++){
            if(i!=0) nums[i]+=nums[i-1];
            ans+=mp[nums[i]-k];
            if(nums[i]==k) ans++;
            mp[nums[i]]++;
        }
        return ans;
    }
};