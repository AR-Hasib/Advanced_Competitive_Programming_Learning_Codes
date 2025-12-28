/* https://codeforces.com/problemset/problem/1033/B

time 2s
Alice has a lovely piece of cloth. It has the shape of a square with a side of length a centimeters.
Bob also wants such piece of cloth. He would prefer a square with a side of length b centimeters (where b<a).
Alice wanted to make Bob happy, so she cut the needed square out of the corner of her piece and gave it to Bob.
Now she is left with an ugly L shaped cloth (see pictures below).

Alice would like to know whether the area of her cloth expressed in square centimeters is prime. Could you help her to determine it?

Input
The first line contains a number t (1≤t≤5) — the number of test cases.

Each of the next t lines describes the i-th test case. It contains two integers a and b (1≤b<a≤10^11) — the side length of Alice's square and the side length of the square that Bob wants.

Output
Print t lines, where the i-th line is the answer to the i-th test case. Print "YES" (without quotes) if the area of the remaining piece of cloth is prime, otherwise print "NO".
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
        int a,b; cin>>a>>b;
        int x= (a*a - b*b);
        bool flag= true; 
 
        if(a-b != 1) flag= false; // a*a - b*b = (a+b)*(a-b)
        else{
            int y= a+b;
            for(int i=2; i<=sqrt(y); i++){
                if(y%i==0) flag= false;
            }
        }

        if(flag==false) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}