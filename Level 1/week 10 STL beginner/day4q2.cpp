/* https://cses.fi/problemset/task/1755/

Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).
Input
The only input line has a string of length n consisting of characters A–Z.
Output
Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".
Constraints

1 <= n <= 10^6

Example
Input:
AAAACACBA

Output:
AACABACAA
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
    map<char, int>mp;

    for(auto c : s){
        mp[c]++;
    }

    int odd=0;
    for(auto it : mp){
        if(it.second % 2 != 0) odd++;
    }

    if(odd>1) cout<<"NO SOLUTION"<<endl;
    else{
        string left, right, middle;
        for(auto it : mp){
            if(it.second % 2 != 0) middle=it.first;
            int x= it.second/2;
            while(x--){
                left.push_back(it.first);
            }
        }
        right= left;
        reverse(right.begin(), right.end());
        if(middle!="/0") cout<<left+middle+right;
        else cout<<left+right;
    }

    return 0;
}