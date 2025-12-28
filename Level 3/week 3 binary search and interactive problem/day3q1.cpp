/* https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/ */


class Solution {
public:
    bool check(vector<int>& nums, int n, int distance, int k){
        int count=0;

        int i=0, j=0;
        while(i<n){
            while((nums[j]-nums[i]) <= distance && j<n) j++;
            j--;
            count+= j-i;
            i++;
            //j=i; no need of this because j-i is already less than distance
            if(count>=k) return true;
        }

        return count>=k;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int left=0, right= nums[n-1]-nums[0];

        int ans=-1;
        while(left<=right){
            int mid= (left+right)/2;

            if(check(nums, n, mid, k)){
                ans=mid;
                right=mid-1;
            }else left=mid+1;

        }
        return ans;
    }
};

