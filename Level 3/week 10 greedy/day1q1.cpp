/* https://codeforces.com/problemset/problem/1348/A */

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

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n; cin>>n;
    ll pile1=0, pile2=0;

    /* 2^1 + 2^2 + ...... + 2^(n-1) = 2^n -2 
    so our approach is to choose the first n/2 -1 element and the last element in a pile */

    // pile1 = pow(2, n/2) - 2 + pow(2, n);
    // pile2 = pow(2, n) - 2 - pow(2, n/2) + 2;

    ll ans = 2*(pow(2, n/2)) -2;

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