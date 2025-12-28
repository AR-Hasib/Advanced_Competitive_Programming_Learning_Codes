/* https://codeforces.com/problemset/problem/1285/C */

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
    pair<ll, ll>ab={1, n};
    for(ll a=2; a*a<=n; a++){
        if(n%a==0){
            ll b= n/a;
            if(__gcd(a, b)==1){
                ab.first=a;
                ab.second=b;
            }
        }
    }
    cout<<ab.first<<" "<<ab.second<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}