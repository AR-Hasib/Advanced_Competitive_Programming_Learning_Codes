/* https://cses.fi/problemset/task/1095/ */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

ll fastPower(ll a, ll b){
    if(b==0) return 1;

    ll ans=fastPower(a, b/2);
    ans*=ans;
    ans%=MOD;
    if(b&1){
        ans*=a;
        ans%=MOD;
    }
    return ans;
}

void solve(){
    ll a, b; cin>>a>>b;
    cout<<fastPower(a, b)<<endl;
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    ll tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}