/* https://codeforces.com/problemset/problem/1458/A */

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

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

void solve(){
    int n, m; cin>>n>>m;
    vector<int>arr(n);
    vector<int>brr(m);
    for(auto &i:arr) cin>>i;
    for(auto &i:brr) cin>>i;

    sort(arr.rbegin(), arr.rend());

    int pm=0;
    for(int i=1; i<n; i++) pm= __gcd(pm, arr[i-1]-arr[i]);

    for(int j=0; j<m; j++){
        int ans= __gcd(arr[0]+brr[j], pm);  
        cout<<ans<<" ";
    }
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    solve();

    return 0;
}