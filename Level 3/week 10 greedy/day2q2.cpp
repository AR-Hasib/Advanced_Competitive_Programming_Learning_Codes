/* https://cses.fi/problemset/task/1074 */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ll long long
#define ld long double
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define precision fixed<<setprecision

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<int> v(n);
    for(auto &i:v) cin>>i;

    sort(v.begin(), v.end());
    int median;
    if(n&1) median = v[n/2];
    else median = (v[n/2 -1] + v[n/2])/2;

    ll ans=0;
    for(auto i:v) ans += abs(median-i);

    cout<<ans<<endl;
    
    return 0;
}