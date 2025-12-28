/* https://codeforces.com/contest/903/problem/C

time 1s

Mishka has got n empty boxes. For every i (1 ≤ i ≤ n), i-th box is a cube with side length ai.
Mishka can put a box i into another box j if the following conditions are met:

    - i-th box is not put into another box;
    - j-th box doesn't contain any other boxes;
    - box i is smaller than box j (ai < aj).

Mishka can put boxes into each other an arbitrary number of times. He wants to minimize the number of visible boxes. 
A box is called visible iff it is not put into some another box.

Help Mishka to determine the minimum possible number of visible boxes!

Input
The first line contains one integer n (1 ≤ n ≤ 5000) — the number of boxes Mishka has got.

The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 10^9), where ai is the side length of i-th box.

Output
Print the minimum possible number of visible boxes.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    map<int, int>m;
    while(n--){
        int i; cin>>i;
        m[i]++;
    }

    int mx= 0;
    for(auto it : m){
        mx= max(mx, it.second);
    }

    cout<<mx;

    return 0;
}