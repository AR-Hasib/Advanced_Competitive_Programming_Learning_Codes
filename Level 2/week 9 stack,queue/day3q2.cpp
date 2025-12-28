/* https://leetcode.com/problems/remove-duplicate-letters/description/ */



#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

string removeDuplicateLetters(string s) {
    map<char, int>freq;
    map<char, bool>seen;
    stack<char>st;

    for(int i=0; i<s.size(); i++) freq[s[i]]++; 
     
    
    for(int i=0; i<s.size(); i++){
        char curr=s[i];
        freq[curr]--;

        if(seen[curr]) continue;
        
        while(st.size()>0 && st.top()>curr && freq[st.top()]>0){
            seen[st.top()]=false;
            st.pop();
        }
        st.push(curr);
        seen[curr]=true;
    }

    string ans="";
    while(st.size()>0){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    string s; cin>>s;

    string ans= string(removeDuplicateLetters(s));
    cout<<ans<<endl;

    return 0;
}