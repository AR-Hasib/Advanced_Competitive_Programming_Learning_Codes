/* https://atcoder.jp/contests/abc148/tasks/abc148_e */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

int count(int x){
    int ans=0;
    for(int i=5; i<=x; i*=5) ans += x/i;
    return ans;
}

void solve(){
    int n; cin>>n;

    if(n&1) cout<<0<<endl;
    else cout<<count(n/2)<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    solve();

    return 0;
}