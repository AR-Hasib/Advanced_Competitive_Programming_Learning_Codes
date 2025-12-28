/* https://codeforces.com/problemset/problem/797/A */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    ll n, k; cin>>n>>k;
    vector<ll>ans;

    if(k==1){
        cout<<n;
        return;
    }

    for(ll i=2; i*i<=n; i++){
        while(n%i==0){
            k--;
            n/=i;
            ans.push_back(i);
            if(k==1) break;
        }
        if(k==1){
            if(n==1) break;
            for(auto i:ans) cout<<i<<" ";
            cout<<n;  
            return;
        }
    }
    cout<<-1; 
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}