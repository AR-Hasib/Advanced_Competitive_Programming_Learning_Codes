/* https://codeforces.com/contest/776/problem/B */

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
    
    int sieve[100005];
    for(int i=0; i<100005; i++) sieve[i]=0;

    int n; cin>>n;
    for(int i=2; i<=n+1; i++){
        if(!sieve[i]){
            for(int j=2*i; j<=n+1; j+=i) sieve[j]=1;
        }
    }

    if(n>2) cout<<2<<endl;
    else cout<<1<<endl;

    for(int i=2; i<=n+1; i++){
        if(!sieve[i]) cout<<1<<" ";
        else cout<<2<<" ";
    }
    return 0;
}