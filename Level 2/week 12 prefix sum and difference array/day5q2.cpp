/* https://codeforces.com/contest/1398/problem/C */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    map<int, int>mp;
    ll ans=0, sum=0;
    mp[0]=1;
    for(int i=0; i<n; i++){
        sum+= int(s[i])-48-1;
        ans+=mp[sum];
        mp[sum]++;
    }
    cout<<ans<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}