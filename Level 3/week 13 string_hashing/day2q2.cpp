/* https://leetcode.com/problems/longest-happy-prefix/ */

class Solution {
public:
    struct Hash {
        const long long MOD = 1e9 + 7, B1 = 5689, B2 = 8861;
    
        vector<pair<long long, long long>> hashes, power;
        // we are maintaining 1 base indexing
        Hash(string s) {
            hashes.assign(s.size() + 1, {0, 0});
            power.assign(s.size() + 1, {1, 1});
    
            for (long long i = 0; i < s.size(); i++) { // creating prefix
                hashes[i + 1] = {
                    (1ll * hashes[i].first * B1 + (s[i] - 'a' + 1)) % MOD,
                    (1ll * hashes[i].second * B2 + (s[i] - 'a' + 1)) % MOD
                };
                power[i + 1] = {
                    (1ll * power[i].first * B1) % MOD,
                    (1ll * power[i].second * B2) % MOD
                };
            }
        }
    
        pair<long long, long long> sHash(long long l, long long r) {
            l++, r++; // as we stored in 1 based indexing but here input is in 0 based indexing
            long long hash1 = (hashes[r].first - (1ll * hashes[l - 1].first * power[r - l + 1].first) % MOD + MOD) % MOD;
            long long hash2 = (hashes[r].second - (1ll * hashes[l - 1].second * power[r - l + 1].second) % MOD + MOD) % MOD;
            return {hash1, hash2};
        }
    };

    string longestPrefix(string s) {
        long long ans=-1;
        Hash a(s);
        long long n = s.size();
        long long i=0, j=n-1;
        while(i<n-1){
            pair<long long, long long> one = a.sHash(0, i);
            pair<long long, long long> two = a.sHash(j, n-1);
            if(one==two) ans = i;
            i++; j--;
        }

        if(i==-1) return "";
        else{
            return s.substr(0, i);
        }
    }
};

/* this solution is done by using hashing. but there is a very easy brute force solution.
match the character from front and back, where it differ just break there and print the substring from 
start to just before of that character*/