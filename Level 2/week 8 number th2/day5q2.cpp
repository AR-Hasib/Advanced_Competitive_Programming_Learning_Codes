/* https://codeforces.com/problemset/problem/1165/D */

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
    ll arr[n];
    for(ll i=0; i<n; i++) cin>>arr[i];
    sort(arr, arr+n);
    ll x= arr[0]*arr[n-1];

    vector<ll>fact;
    for(ll i=2; i*i<=x; i++){
        if(x%i==0){
            fact.push_back(i);
            if(x/i!=i) fact.push_back(x/i);
        }
    }
    sort(fact.begin(), fact.end());

    for(ll i=0; i<n; i++){
        if(arr[i]!=fact[i]){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<x<<endl;
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