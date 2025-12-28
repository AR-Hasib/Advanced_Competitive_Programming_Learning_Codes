/* https://atcoder.jp/contests/abc164/tasks/abc164_c

Problem Statement
You drew lottery N times. In the i-th draw, you got an item of the kind represented by a string Sį.
How many kinds of items did you get?

Constraints
• 1≤N≤ 2 x 10^5
• S; consists of lowercase English letters and has a length between 1 and 10 (inclusive).

Input
Input is given from Standard Input in the following format:
N
S1
:
SN

Output
Print the number of kinds of items you got.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    set<string>st;
    string s;
    while(n--){
        cin>>s;
        st.insert(s);
    }
    cout<<st.size();
    return 0;
}