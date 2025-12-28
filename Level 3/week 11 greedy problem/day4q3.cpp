/* https://codeforces.com/problemset/problem/1338/A */

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
    vector<int> v(n);
    for(auto &i:v) cin>>i;

    int second=-1;

    for(int i=1; i<n; i++){
        if(v[i-1] <= v[i]) continue;
        
        int diff = v[i-1] - v[i];
        int need = log2(diff);
        second = max(second, need);
        v[i] = v[i-1];
    }
    cout<<second+1<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}