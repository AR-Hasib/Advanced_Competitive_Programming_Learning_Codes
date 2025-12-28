/* https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/ */

class Solution {
public:

    bool check(vector<int>arr, int n, int target, int k, int curr){
        int temp=0, count=0;
        for(int i=0; i<n; i++){
            if(arr[i]<=curr){
                temp++;
                if(temp==k){
                    temp=0;
                    count++;
                }
            }else{
                temp=0;
            }

            if(count>=target) return true;
        }
        return count>=target;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int left=INT_MAX, right=0, n=bloomDay.size();
        if(static_cast<long long>(m*k) > static_cast<long long>(n)) return -1;

        for(int i=0; i<n; i++){
            left=min(left, bloomDay[i]);
            right=max(right, bloomDay[i]);
        }

        int ans=-1;
        while(left<=right){
            int mid=(left+right)/2;

            if(check(bloomDay, n, m, k, mid)){
                ans=mid;
                right=mid-1;
            }else left=mid+1;
        }

        return ans;
    }
};