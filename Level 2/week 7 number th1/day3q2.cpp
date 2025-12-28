/* https://codeforces.com/problemset/problem/230/B */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

vector<int>prime;

void sieve(ll n){
    prime.assign(n, 0);
    prime[0]=prime[1]=1;
    for(ll i=2; i*i<=n; i++){
        if(!prime[i]){
            for(int j=i*i; j<=n; j+=i) prime[j]=1;
        }
    }
}

signed main(){
    
    sieve(1e6);

    ll n; cin>>n;
    ll arr[n];
    for(ll i=0; i<n; i++) cin>>arr[i];
    for(ll i=0; i<n; i++){
        ll x= arr[i];
        ll temp= sqrt(x);
        if(temp*temp != x) no;
        else if(!prime[temp]) yes;
        else no;
    }
    
    return 0;
}