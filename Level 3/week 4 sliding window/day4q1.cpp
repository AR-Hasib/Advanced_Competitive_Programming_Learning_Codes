/* https://cses.fi/problemset/task/1076 */

// policy based data structure has been used here
/* We use the tree container from pbds, which acts like an ordered set with additional 
functionalities (like finding the order of an element or accessing by index). */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int>v(n);
    for(auto &i:v) cin>>i;

    ordered_set<pair<int, int>> s;
    for(int i=0; i<k-1; i++){
        s.insert({v[i], i});
    }

    for(int i=k-1; i<n; i++){
        s.insert({v[i], i});
        int ans= s.find_by_order((k-1)/2)->first;
        s.erase(s.find({v[i-k+1], i-k+1}));
        cout<<ans<<" ";
    }
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}