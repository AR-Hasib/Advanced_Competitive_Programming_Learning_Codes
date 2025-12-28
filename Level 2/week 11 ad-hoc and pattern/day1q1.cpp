/* https://codeforces.com/contest/1918/problem/B */

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
    pair<ll, ll>arr[n];

    for(ll i=0; i<n; i++) cin>>arr[i].first;
    for(ll i=0; i<n; i++) cin>>arr[i].second;

    sort(arr, arr+n);
    for(ll i=0; i<n; i++) cout<<arr[i].first<<" ";
    cout<<endl;
    for(ll i=0; i<n; i++) cout<<arr[i].second<<" ";
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