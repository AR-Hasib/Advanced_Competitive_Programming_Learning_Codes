/* https://leetcode.com/problems/sqrtx/description/

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

Example 1:
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 
Constraints:
0 <= x <= 2^31 - 1
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int x; cin >> x;
    if(x<1) cout<<x;
    else{
        long long s=2, e=x, ans=1; 
        while (s<=e) {
            long long mid=(s+e)/2;
            if(mid*mid<=x){
                ans= mid;
                s= mid+1;
            }else e= mid-1;
        }
        cout<<ans;
    }
    return 0;
}