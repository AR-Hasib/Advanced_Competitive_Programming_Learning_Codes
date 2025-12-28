/* https://codeforces.com/contest/1629/problem/B

time 2s
Consider the array a composed of all the integers in the range [1, r]. For example, if I = 3 and r = 7, then a = [3, 4, 5, 6, 7].
Given 1, r, and k, is it possible for gcd(a) to be greater than 1 after doing the following operation at most k times?
• Choose 2 numbers from a
• Permanently remove one occurrence of each of them from the array.
• Insert their product back into a
gcd(b) denotes the greatest common divisor (GCD) of the integers in b.

Input
The first line of the input contains a single integer t (1 ≤ t ≤ 105) — the number of test cases. The description of test cases follows.
The input for each test case consists of a single line containing 3 non-negative integers l, r, and k (1 ≤ 1 ≤ r ≤ 10⁰, 0≤k ≤r-l).

Output
For each test case, print "YES" if it is possible to have the GCD of the corresponding array greater than 1 by performing at most k
operations, and "NO" otherwise (case insensitive).
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        int l, r, k; cin>>l>>r>>k;

        if(l==r){
            if(l==1) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }else{
            int total= r-l+1;
            int odd= total/2;
            if((total%2==1) && (l%2==1)) odd++;

            if(odd<=k) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}