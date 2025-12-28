#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

bool solve(ll sum, ll i, ll n, ll x, ll arr[]){
    if(i==n) return sum==x;
    bool ans1=solve(sum+arr[i], i+1, n, x, arr);
    bool ans2=solve(sum-arr[i], i+1, n, x, arr);
    return ans1||ans2;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    ll n, x; cin>>n>>x;
    ll arr[n];
    for(ll i=0; i<n; i++) cin>>arr[i];
    if(solve(arr[0], 1, n, x, arr)) yes;
    else no;
    return 0;
}