/* https://codeforces.com/problemset/problem/550/A 

You are given string s. Your task is to determine if the given string s contains two non-overlapping 
substrings "AB" and "BA" (the substrings can go in any order).

Input
The only line of input contains a string s of length between 1 and 10^5 consisting of uppercase Latin letters.

Output
Print "YES" (without the quotes), if string s contains two non-overlapping substrings "AB" and "BA", and "NO" otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    string s; cin>>s;
    int x1= s.find("AB"); int x2= s.find("BA", x1+2);
    if(x1>=0 && x2>=0) cout<<"YES";
    else{
        x1= s.find("BA"); x2= s.find("AB", x1+2);
        if(x1>=0 & x2>=0) cout<<"YES";
        else cout<<"NO";
    }

    return 0;
}