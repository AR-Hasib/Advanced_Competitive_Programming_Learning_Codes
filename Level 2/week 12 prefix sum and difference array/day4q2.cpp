/* https://codeforces.com/contest/276/problem/C */

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
    
    int n, q; cin>>n>>q;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr, arr+n);

    vector<ll>range(n, 0);
    while(q--){
        int l, r; cin>>l>>r;
        l--; r--;
        range[l]++;
        if(r+1<n) range[r+1]--;
    }

    for(int i=1; i<n; i++) range[i]+=range[i-1];
    sort(range.begin(), range.end());

    ll ans=0;
    for(int i=0; i<n; i++) ans+= 1ll*range[i]*arr[i];
    cout<<ans<<endl;

    return 0;
}