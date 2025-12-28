/* https://cses.fi/problemset/task/1145 */

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
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(auto &i:a) cin>>i;

    vector<int>dp;
    for(int i=0; i<n; i++){
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        if(it == dp.end()) dp.push_back(a[i]);
        else *it = a[i];
    }
    cout<<dp.size()<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}