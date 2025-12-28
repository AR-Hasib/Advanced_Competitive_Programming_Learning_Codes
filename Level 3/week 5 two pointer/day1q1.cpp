/* https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    ll n, m; cin>>n>>m;
    vector<ll>a(n), b(m);
    for(auto &i:a) cin>>i;
    for(auto &i:b) cin>>i;

    map<ll, ll>am, bm;
    for(auto i:a) am[i]++;
    for(auto i:b) bm[i]++;

    ll ans=0;
    for(auto i:am){
        ans+= i.second*bm[i.first];
    }
    cout<<ans;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    solve();
    
    return 0;
}