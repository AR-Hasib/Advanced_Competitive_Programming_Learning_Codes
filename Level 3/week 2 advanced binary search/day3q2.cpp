/* https://leetcode.com/problems/find-the-duplicate-number/description/ */

class Solution {
public:
    bool check(vector<int>nums, int mid){
        int count=0;
        for(auto it:nums){
            if(it<=mid) count++;
        }
        return count<=mid;
    }

    int findDuplicate(vector<int>& nums) {
        int n= nums.size();
        int ans=-1, l=1, r=n;

        while(l<=r){
            int mid=(l+r)/2;

            if(check(nums, mid)){
                l=mid+1;
            }else{
                ans=mid;
                r=mid-1;
            }
        }

        return ans;
    }
};