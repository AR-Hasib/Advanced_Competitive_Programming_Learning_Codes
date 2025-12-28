/* https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/ */

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size(), ans=0, flip=0;
        for(int i=0; i<n; i++){
            if(i>=k && nums[i-k]>1){    // reducing flip which is not affecting any more. 
                flip--;
                nums[i-k]-=2;           // restore initial array
            }

            if((nums[i]==0 && flip%2==0) || (nums[i]==1 && flip%2==1)){ // when i need to flip
                if(i+k>n) return -1;
                ans++;
                nums[i]+=2;
            }

            if(nums[n-k]>1) nums[n-k]-=2;  // just restoring. it can be ignored
        }
        return ans;
    }
};
