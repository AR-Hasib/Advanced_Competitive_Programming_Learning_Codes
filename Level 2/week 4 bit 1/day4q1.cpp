/* https://codeforces.com/problemset/problem/1312/C */

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
    ll arr[n];
    for(ll i=0; i<n; i++) cin>>arr[i];

    ll big= *max_element(arr, arr+n);
    ll value=1;
    while(value<big) value*=k;

    bool flag=true;
    while(value>0){
        int cnt=0;
        for(int i=0; i<n; i++){
            if(arr[i] >= value){
                arr[i]-=value;
                cnt++;
            }
        }
        if(cnt>1){
            flag=false;
            break;
        }
        value/=k;
    }
    if(flag){
        for(int i=0; i<n; i++){
            if(arr[i]!=0){
                no;
                return;
            }
        }
        yes;
    }else no;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}