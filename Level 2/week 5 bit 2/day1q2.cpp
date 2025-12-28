/* https://www.codechef.com/problems/ORTUPLES */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int p, q, r;
    cin>>p>>q>>r;
    ll ans=1;
    for(int i=0; i<20; i++){
        int cnt=0;
        if(p&(1<<i)) cnt++;
        if(q&(1<<i)) cnt++;
        if(r&(1<<i)) cnt++;
        if(cnt==1){
            cout<<0<<endl;
            return;
        }else if(cnt==3){
            ans*=4;
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