/* https://codeforces.com/problemset/problem/1305/C */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    ll n, m; cin>>n>>m;
    ll arr[n];
    for(ll i=0; i<n; i++) cin>>arr[i];
    ll ans=1;
    if(n>m) ans=0;
    else{
        for(ll i=0; i<n; i++){
            for(ll j=i+1; j<n; j++){
                ll x= abs(arr[i]-arr[j]);
                ans*=x;
                ans%=m;
            }
        }
    }
    
    cout<<ans<<endl;
    return 0;
}