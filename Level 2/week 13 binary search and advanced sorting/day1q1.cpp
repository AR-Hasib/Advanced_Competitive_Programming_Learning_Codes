/* https://leetcode.com/problems/find-peak-element/description/ */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();

        if(n==1) return 0;
        else if(nums[0]>nums[1]) return 0;
        else if(nums[n-2]<nums[n-1]) return n-1;
        else{
            int left=1, right=n-2; 
            while(left<=right){
                int mid=(left+right)/2;
                if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]) return mid; // peak found
                else if(nums[mid-1]>nums[mid]) right= mid-1; // left is increasing
                else left= mid+1; // right is increasing
            }
        }
        return -1;
    }
};