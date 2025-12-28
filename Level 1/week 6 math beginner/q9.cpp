/* https://codeforces.com/contest/1617/problem/B

Given a positive integer n. Find three distinct positive integers a, b, c such that a + b +c = n and gcd(a, b) = c, where gcd(x, y)
denotes the greatest common divisor (GCD) of integers x and y.
Input
The input consists of multiple test cases. The first line contains a single integer t (1 ≤ t ≤ 105) — the number of test cases. Description of
the test cases follows.
The first and only line of each test case contains a single integer n (10 ≤ n ≤ 10⁹).
Output
For each test case, output three distinct positive integers a, b, c satisfying the requirements. If there are multiple solutions, you can print
any. We can show that an answer always exists. */

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
        int a=1, b;

        for(int a=1; a<n-1; a++){
            b= n-a-1;
            int c= __gcd(a, b);
            if(c==1 && a!=1 && b!=a){
                cout<<a<<" "<<b<<" "<<"1"<<endl;
                break;
            }
        }
    }
    return 0;
}