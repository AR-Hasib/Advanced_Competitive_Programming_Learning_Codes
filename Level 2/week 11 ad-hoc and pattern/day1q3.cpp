/* https://codeforces.com/problemset/problem/1791/G1 */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    ll n, cost; cin>>n>>cost;
    ll arr[n];
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr[i]=temp+i+1;
    }
    sort(arr, arr+n);

    ll i=0;
    while(i<n && cost>0){
        cost-=arr[i];
        i++;
    }

    if(cost<0) i--;
    cout<<i<<endl;
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