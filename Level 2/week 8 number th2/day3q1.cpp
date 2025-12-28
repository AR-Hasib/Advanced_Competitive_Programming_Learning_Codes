/* https://leetcode.com/problems/super-pow/description/ */

class Solution {
public:
    long long MOD=1337;
    long long fastPower(long long a, long long b){
        if(b==0) return 1;

        long long ans=fastPower(a, b/2);
        ans*=ans;
        ans%=MOD;
        if(b&1){
            ans*=a;
            ans%=MOD;
        }
        return ans;
    }

    int superPow(int a, vector<int>& b) {
        long long ans=1;
        for(auto digit:b){
            ans= (fastPower(ans, 10))%MOD * (fastPower(a, digit))%MOD;
        }
        return ans;
    }
};