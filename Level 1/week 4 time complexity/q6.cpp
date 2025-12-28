/* https://codeforces.com/problemset/problem/1269/A

Let's call a positive integer composite if it has at least one divisor other than 1 and itself. For example:
• the following numbers are composite: 1024, 4, 6, 9;
• the following numbers are not composite: 13, 1, 2, 3, 37.
You are given a positive integer n. Find two composite integers a, b such that a-b=n
It can be proven that solution always exists.

Input
The input contains one integer n (1 ≤ n ≤ 107): the given integer.

Output
Print two composite integers a, b (2 ≤ a,b ≤ 10%, a - b = n).
It can be proven, that solution always exists.
If there are several possible solutions, you can print any.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int a, b, n; cin>>n;
    bool flagA, flagB;

    for(int i=2; i<=10e9; i++){
        flagB= false; flagA= false;
        for(int x=2; x<=(i/2); x++){
            if(i%x == 0){
                flagB= true;
                break;
            }
        }

        if(flagB == true){
            b= i;
            a= b+n;
            for(int j=2; j<=(a/2); j++){
                if(a%j == 0){
                    flagA= true;
                    break;
                }
            }
        }

        if(flagA==true && flagB==true){
            cout<<a<<" "<<b;
            return 0;
        }
    }
}