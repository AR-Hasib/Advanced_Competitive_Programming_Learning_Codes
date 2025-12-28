/* https://leetcode.com/problems/valid-parentheses/description/ */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

bool isValid(string s){
    stack<char>st;
    for(auto digit:s){
        if(digit=='(' || digit=='{' || digit=='['){
                st.push(digit);
                continue;
            } 
            if(digit==')') if(st.empty() || st.top()!='(') return false;
            if(digit=='}') if(st.empty() || st.top()!='{') return false;
            if(digit==']') if(st.empty() || st.top()!='[') return false;
            st.pop();
    }
    return st.empty();
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    string s; cin>>s;
    cout<<isValid(s);
    return 0;
}