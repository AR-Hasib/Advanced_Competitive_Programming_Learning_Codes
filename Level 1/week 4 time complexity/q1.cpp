/* https://atcoder.jp/contests/abc242/tasks/abc242_b

sorting string character
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    string s; cin>>s;
    sort(s.begin(), s.end());
    cout<<s;
}