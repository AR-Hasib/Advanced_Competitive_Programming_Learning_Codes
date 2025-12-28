/* https://www.codechef.com/submit/ANDSUBAR */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

void solve(){
    int n; cin>>n;
    int ans=0;
    int curr=1;
    while(curr<=n){
        int nxt= min(n, (2*curr)-1);
        ans= max(ans, nxt-curr+1);
        curr*=2; 
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