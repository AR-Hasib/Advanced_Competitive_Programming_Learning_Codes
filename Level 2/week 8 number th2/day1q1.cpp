/* https://codeforces.com/contest/1765/problem/M */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

ll lcm(ll x, ll y){
    return (x*y)/__gcd(x, y);
}

void solve(){
    ll n; cin>>n;
    ll a=1, b=n-1;
    ll ans= lcm(a, b);

    for(ll i=2; i*i<=n; i++){
        if(n%i==0){
            ll temp= lcm(i, n-i);
            if(temp<ans){
                ans=temp;
                a=i; b=n-i;
            }
            if(n/i != i){
                ll c= n/i;
                ll temp= lcm(c, n-c);
                if(temp<ans){
                    ans=temp;
                    a=c; b=n-c;
                }
            }
        }
    }
    cout<<a<<" "<<b<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}