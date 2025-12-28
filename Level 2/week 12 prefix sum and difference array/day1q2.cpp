/* https://cses.fi/problemset/task/1661 */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    ll n, x; cin>>n>>x;
    ll arr[n], sum=0, ans=0;
    for(int i=0; i<n; i++) cin>>arr[i];

    map<ll, int>mp;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        ans+=mp[sum-x];
        if(sum==x) ans++;
        mp[sum]++;
    }
    cout<<ans<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}