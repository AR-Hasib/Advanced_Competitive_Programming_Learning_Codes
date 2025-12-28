/* https://codeforces.com/contest/1914/problem/E2 */

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

bool compare(pair<int, int> &a, pair<int, int> &b){
    return (a.first+a.second) > (b.first+b.second);
}

void solve(){
    int n; cin>>n;
    vector<pair<int, int>> v(n);
    for(auto &i:v) cin>>i.first;
    for(auto &i:v) cin>>i.second;

    sort(v.begin(), v.end(), compare);
    int ans=0;

    for(int i=0; i<n; i++){
        if(i&1) ans -= (v[i].second-1);     // bob's turn
        else ans += (v[i].first-1);
    }

    cout<<ans<<endl;
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}