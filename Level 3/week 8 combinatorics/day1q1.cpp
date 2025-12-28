/* https://cses.fi/problemset/task/1717 */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define int long long
#define ld long double
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define precision fixed<<setprecision

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

void solve(){
    int n; cin>>n;
    vector<int> d(n+1);
    d[0]=1; d[1]=0;
    for(int i=2; i<=n; i++){
        d[i] = ((i-1)*((d[i-1]+d[i-2])%MOD))%MOD;
    }
    cout<<d[n]<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}