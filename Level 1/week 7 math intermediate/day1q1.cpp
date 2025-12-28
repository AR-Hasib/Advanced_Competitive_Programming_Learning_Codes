/* https://codeforces.com/contest/1328/problem/A

You are given two positive integers a and b. In one move you can increase a by 1 (replace a with a + 1). Your task is to find the minimum
number of moves you need to do in order to make a divisible by b. It is possible, that you have to make 0 moves, as a is already divisible
by b. You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1 ≤ t ≤ 10^4) — the number of test cases. Then t test cases follow.
The only line of the test case contains two integers a and b (1 ≤ a,b ≤ 10^9).

Output
For each test case print the answer the minimum number of moves you need to do in order to make a divisible by b.
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
        int a, b; cin>>a>>b;
        if(a%b == 0) cout<<0<<endl;
        else {
            int x= a/b;
            cout<<(b*(x+1))-a<<endl;
        }
    }
    return 0;
}