/* https://codeforces.com/problemset/problem/1360/D */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    ll n, k; cin>>n>>k;
    if(n<=k){
        cout<<1<<endl;
        return;
    }

    ll ans=LLONG_MAX;
    for(ll i=1; i*i<=n; i++){
        if(n%i==0){
            ll j=n/i;
            if(j<=k) ans=min(ans, i);
            else if(i<=k) ans=min(ans, j);
            if(i>k) break;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    ll tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}