/* https://codeforces.com/problemset/problem/1767/D */

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
#define toLDouble static_cast<long double>

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    int cnt0=0, cnt1=0;
    for(auto i:s){
        if(i=='0') cnt0++;
        else cnt1++;
    }


    int l = (1 << cnt1)-1, g = (1 << cnt0)-1;   // smaller element need in left, greater element need in right side
    int r = (1 << n) - g;

    for(int i=l+1; i<=r; i++) cout<<i<<" ";
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}