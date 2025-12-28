/* https://atcoder.jp/contests/jsc2021/tasks/jsc2021_c

Time Limit: 2 sec/Memory Limit: 1024 MB

Problem Statement
Given are integers A and B. Find the maximum possible value of gcd(x, y) when we choose integers & and y so that A ≤ x ≤ y ≤ B.
Here, gcd (x, y) denotes the greatest common divisor of x and y.

Constraints
A and B are integers.
• 1≤A<B≤ 2 × 10^5

Input
Input is given from Standard Input in the following format:
A B

Output
Print the answer.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

int f(int a, int b, int g){
    return (b/g)-((a-1)/g);
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int a, b; cin>>a>>b;
    int g=b;
    while(f(a, b, g)<2){
        g--;
    }
    cout<<g;
    return 0;
}