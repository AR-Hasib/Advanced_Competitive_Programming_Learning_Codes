/* https://codeforces.com/contest/1549/problem/A

Gregor is learning about RSA cryptography, and although he doesn't understand how RSA works, he is now fascinated with prime numbers
and factoring them.
Gregor's favorite prime number is P. Gregor wants to find two bases of P. Formally, Gregor is looking for two integers a and b which
satisfy both of the following properties.
P mod a = P mod b, where x mod y denotes the remainder when x is divided by y, and
• 2 ≤a < b < P.
Help Gregor find two bases of his favorite prime number!
Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 1000).
Each subsequent line contains the integer P (5 ≤ P ≤ 10^9), with P guaranteed to be prime.
Output
Your output should consist of t lines. Each line should consist of two integers a and b (2 ≤ a < b ≤ P). If there are multiple possible
solutions, print any.
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
        int n; cin>>n;
        if(n==5) cout<<"2 4"<<endl;
        else{
            n-=1;
            for(int i=2; i<=sqrt(n); i++){
                if(n%i==0){
                    cout<<i<<" "<<n/i<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}