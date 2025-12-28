/* https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/ */

//leet code

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

class Solution {
public:
    void solve(vector<string>&ans, string &s, int idx, string &curr){
        if(idx==s.length()){
            ans.push_back(curr);
            return;
        }

        if(s[idx]=='2'){
            curr[idx]='a';
            solve(ans, s, idx+1, curr);
            curr[idx]='b';
            solve(ans, s, idx+1, curr);
            curr[idx]='c';
            solve(ans, s, idx+1, curr);
        }
        else if(s[idx]=='3'){
            curr[idx]='d';
            solve(ans, s, idx+1, curr);
            curr[idx]='e';
            solve(ans, s, idx+1, curr);
            curr[idx]='f';
            solve(ans, s, idx+1, curr);
        }
        else if(s[idx]=='4'){
            curr[idx]='g';
            solve(ans, s, idx+1, curr);
            curr[idx]='h';
            solve(ans, s, idx+1, curr);
            curr[idx]='i';
            solve(ans, s, idx+1, curr);
        }
        else if(s[idx]=='5'){
            curr[idx]='j';
            solve(ans, s, idx+1, curr);
            curr[idx]='k';
            solve(ans, s, idx+1, curr);
            curr[idx]='l';
            solve(ans, s, idx+1, curr);
        }
        else if(s[idx]=='6'){
            curr[idx]='m';
            solve(ans, s, idx+1, curr);
            curr[idx]='n';
            solve(ans, s, idx+1, curr);
            curr[idx]='o';
            solve(ans, s, idx+1, curr);
        }
        else if(s[idx]=='7'){
            curr[idx]='p';
            solve(ans, s, idx+1, curr);
            curr[idx]='q';
            solve(ans, s, idx+1, curr);
            curr[idx]='r';
            solve(ans, s, idx+1, curr);
            curr[idx]='s';
            solve(ans, s, idx+1, curr);
        }
        else if(s[idx]=='8'){
            curr[idx]='t';
            solve(ans, s, idx+1, curr);
            curr[idx]='u';
            solve(ans, s, idx+1, curr);
            curr[idx]='v';
            solve(ans, s, idx+1, curr);
        }
        else if(s[idx]=='9'){
            curr[idx]='w';
            solve(ans, s, idx+1, curr);
            curr[idx]='x';
            solve(ans, s, idx+1, curr);
            curr[idx]='y';
            solve(ans, s, idx+1, curr);
            curr[idx]='z';
            solve(ans, s, idx+1, curr);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits=="") return ans;
        else{
            string curr(digits.length(), 'A');
            solve(ans, digits, 0, curr);
            return ans;
        }
    }
};

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    string s; cin>>s;
    Solution a;
    vector<string>x = a.letterCombinations(s);
    for(auto i:x) cout<<i<<" ";

    return 0;
}