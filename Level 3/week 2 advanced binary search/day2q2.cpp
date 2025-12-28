/* https://leetcode.com/problems/nth-magical-number/description/ */

class Solution {
public:
    int M= 1e9+7;

    bool check(int n, long long temp, int a, int b){
        long long lc= ((a*b)/gcd(a, b));
        long long count= (temp/a)+(temp/b) - (temp/lc);
        return count>=n;
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long left=n, right=1e16;
        int ans=-1;
        while(left<=right){
            long long mid= (left+right)/2;

            if(check(n, mid, a, b)){
                ans=mid%M;
                right=mid-1;
            }else left=mid+1;
        }

        return ans;

    }
};