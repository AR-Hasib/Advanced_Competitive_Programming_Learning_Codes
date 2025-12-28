/* https://codeforces.com/contest/1437/problem/B */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    string s; int n;
    cin>>n>>s;

    int c0=0, c1=0;
    for(int i=0; i<n-1; i++){
        if(s[i]==s[i+1]){
            if(s[i]=='0') c0++;
            if(s[i]=='1') c1++;
        }
    }
    cout<<max(c0, c1)<<endl;
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}