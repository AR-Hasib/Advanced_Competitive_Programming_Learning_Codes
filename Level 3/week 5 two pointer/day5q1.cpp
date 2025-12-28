/* https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/ */

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>>v;
        int target=nums.size();
        for(int j=0; j<target; j++){
            for(auto i:nums[j]){
                v.push_back({i, j});
            }
        }

        vector<int>ans={-1, -1};
        long long length=1e16;
        sort(v.begin(), v.end());

        int i=0, j=0, n=v.size();
        map<int, int>m;             // this map size has to be equal to target
        while(j<n || i<n){
            while(m.size()<target && j<n){
                m[v[j].second]++;
                j++;
            }
            
            if(j>0 && m.size()>=target && (v[j-1].first-v[i].first)<length){
                length=(v[j-1].first-v[i].first);
                ans[0]=v[i].first;
                ans[1]=v[j-1].first;
            }
            m[v[i].second]--;
            if(m[v[i].second]==0) m.erase(v[i].second);
            i++;
        }
        return ans;
    }
};

// ignore this following part.
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
