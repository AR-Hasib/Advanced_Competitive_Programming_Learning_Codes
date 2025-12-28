/* https://codeforces.com/problemset/problem/1474/B */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

vector<bool>prime;

void sieve(ll n){
    prime.assign(n, true);
    prime[0]=prime[1]=false;
    for(ll i=2; i*i<=n; i++){
        if(prime[i]){
            for(int j=i*i; j<=n; j+=i) prime[j]=false;
        }
    }
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    sieve(1+1e6);
    int tc; cin>>tc;
    while(tc--){
        ll d; cin>>d;
        ll ans=1;
        ll temp=1+d;

        for(ll i=temp; ; i++){
            if(prime[i]){
                temp=i;
                ans*=i;
                break;
            }
        }
        temp+=d;
        for(ll i=temp; ; i++){
            if(prime[i]){
                ans*=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}