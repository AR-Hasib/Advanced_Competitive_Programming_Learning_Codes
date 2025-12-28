/* https://codeforces.com/problemset/problem/1569/C */

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

const int MOD = 998244353;

void solve(){
    int n; cin>>n;
    vector<int>v(n);
    for(auto &i:v) cin>>i;

    int mx=-1;
    for(auto i:v) mx = max(mx, i);
    int countMax = 0, countM = 0;  
    for(auto i:v){
        if(i==mx) countMax++;
        if(i==mx-1) countM++;
    }

    if(countMax==0 && countM==0) cout<<0<<endl;
    else{
        int ans = 1, bad=1;
        for(int i=1; i<=n; i++){
            ans = ((i%MOD)*(ans%MOD))%MOD;
            if(i!=countM+1) bad = ((i%MOD)*(bad%MOD))%MOD;
        }
        if(countMax==1) ans = (ans-bad+MOD)%MOD;
        cout<<ans<<endl;
    }
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}