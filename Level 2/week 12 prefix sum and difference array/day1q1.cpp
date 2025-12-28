/* https://cses.fi/problemset/task/1646 */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n, q; cin>>n>>q;
    int arr[n];
    ll sum[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(i==0) sum[0]=arr[0];
        else sum[i]=sum[i-1]+arr[i];
    }

    while(q--){
        int l, r; cin>>l>>r;
        l--; r--;
        if(l==0) cout<<sum[r]<<endl;
        else cout<<sum[r]-sum[l-1]<<endl;
    }
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}