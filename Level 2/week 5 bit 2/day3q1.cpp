/* https://codeforces.com/problemset/problem/1362/C */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

ll fun(ll n){
    if(n==1) return 1;
    return n+fun(n/2);
}

void solve(){
    ll n; cin>>n;
    ll ans=fun(n);
    cout<<ans<<endl;
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