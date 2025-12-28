/* https://leetcode.com/problems/maximum-score-of-spliced-array/description/ */

class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> v1(n), v2(n);
        int sum1=0, sum2=0;
        for(int i=0; i<n; i++){
            sum1 += nums1[i];
            sum2 += nums2[i];
            v1[i] = nums2[i]-nums1[i];
            v2[i] = nums1[i]-nums2[i];
        }

        int mx1=-1e5, mx2=-1e5, curr1=0, curr2=0;
        for(int i=0; i<n; i++){
            if(curr1<0) curr1=0;
            if(curr2<0) curr2=0;
            curr1 += v1[i];
            curr2 += v2[i];
            mx1 = max(mx1, curr1);
            mx2 = max(mx2, curr2);
        }

        return max(sum1+mx1, sum2+mx2);
    }
};


#include <bits/stdc++.h>
using namespace std;
