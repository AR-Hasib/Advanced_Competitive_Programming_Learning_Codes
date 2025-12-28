/* https://codeforces.com/problemset/problem/1285/B */

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
    vector<int> arr(n);
    for(auto &i:arr) cin>>i;

    ll sum=0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum<=0){
            no; return;
        }
    }

    sum=0;
    for(int i=n-1; i>=0; i--){
        sum += arr[i];
        if(sum<=0){
            no; return;
        }
    }

    yes; return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}