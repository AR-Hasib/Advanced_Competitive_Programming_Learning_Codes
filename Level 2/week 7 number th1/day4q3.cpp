/* https://codeforces.com/problemset/problem/1787/B */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    ll n; cin>>n;
    map<ll, ll>m;
    ll x=1;
    for(ll i=2; i*i<=n; i++){
        if(n%i==0){
            ll cnt=0;
            while(n%i==0){
                n/=i;
                cnt++;
            }
            m[i]=cnt;
            x=max(x, cnt);
        }
    }
    if(n>1) m[n]=1;

    ll ans=0;
    for(ll j=0; j<x; j++){
        ll p=1;
        for(auto it=m.begin(); it!=m.end(); it++){
            if(it->second>0){
                p*=it->first;
                it->second--;
            }
        }
        ans+=p;
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