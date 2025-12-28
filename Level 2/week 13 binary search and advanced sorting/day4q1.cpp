/* https://codeforces.com/problemset/problem/251/A */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    ll n, d; cin>>n>>d;
    vector<int>v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    ll ans=0;
    for(int i=2; i<n; i++){
        int idx= lower_bound(v.begin(), v.end(), v[i]-d)-v.begin();
        ll distance= i-idx;
        if(distance>=2) ans+=(distance*(distance-1))/2;
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