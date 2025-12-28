/* https://codeforces.com/problemset/problem/1669/H */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n, k; cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    ll ans=0;
    for(int i=30; i>=0; i--){
        int bitSet=0;
        for(int j=0; j<n; j++){
            if(arr[j]&(1<<i)) bitSet++;
        }
        int notSet=n-bitSet;
        if(notSet <= k){
            ans|=(1<<i);
            k-=notSet;
        } 
    }
    cout<<ans<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}