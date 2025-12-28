#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

vector<string>all;

void solve(int idx, int size, vector<int>&freq, string curr){
    if(idx==size){
        all.push_back(curr);
        return;
    }
    for(int i=0; i<26; i++){
        if(freq[i]>0){
            freq[i]--;
            solve(idx+1, size, freq, curr+char('a'+i));
            freq[i]++;
        }
    }
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
      
    string s; cin>>s;
    vector<int>f(26);
    for(auto i:s) f[i-'a']++;
    solve(0, s.size(), f, "");
    cout<<all.size()<<endl;
    for( auto i:all) cout<<i<<endl;
    
    return 0;
}