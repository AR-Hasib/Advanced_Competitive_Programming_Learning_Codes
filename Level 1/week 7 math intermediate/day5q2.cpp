/* https://atcoder.jp/contests/caddi2018b/tasks/caddi2018_a

time 2s
Problem Statement
There are N integers a1, a2, ..., ay not less than 1. The values of a1, a2, ..., ay are not known, but it is known that a₁ × ₂ × ... X an = P.
Find the maximum possible greatest common divisor of a1, a2, ..., an.

Constraints
• 1 ≤ N≤ 10^12
• 1< P < 10^12

Input
Input is given from Standard Input in the following format:
N P

Output
Print the answer.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, p; cin>>n>>p;
    int ans=1;

    if(n==1){
        cout<<p;
    }else{
        int i=2, x=1;
        while(x<=p && i<1000){
            x= pow(i, n);
            if(p%x==0) ans=i;
            
            i++;
        } 
    cout<<ans;  
    }
    return 0;
}

