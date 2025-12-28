/* https://atcoder.jp/contests/abc120/tasks/abc120_b

time 2s;
Problem Statement
You are given positive integers A and B.
Find the K-th largest positive integer that divides both A and B.
The input guarantees that there exists such a number.

Constraints
• All values in input are integers.
• 1 ≤ A, B ≤ 100
• The K-th largest positive integer that divides both A and B exists.
• K≥1

Input
Input is given from Standard Input in the following format:
A B K
Output
Print the K-th largest positive integer that divides both A and B.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int a, b, k; cin>>a>>b>>k;
    int val= __gcd(a, b);
    int count=1;
    if(k==1) cout<<val;
    else{
        int i=val-1;
        while(count<k){
            if(a%i==0 && b%i==0) count++;
            i--;
        }
        cout<<i+1;
    }

    return 0;
}