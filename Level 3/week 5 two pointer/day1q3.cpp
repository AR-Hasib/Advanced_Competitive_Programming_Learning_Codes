/* https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/B */

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
    ll n, k; cin>>n>>k;
    vector<ll>v(n);
    for(auto &i:v) cin>>i;

    ll sum=0, ans=0;
    ll j=0;
    for(ll i=0; i<n; i++){

        while(j<n && (sum+v[j])<=k){
            sum+=v[j];
            j++;
        }
    
        ans+= (1ll*(j-i)*(j-i+1))/2;
        sum-=v[i];
    }
    cout<<ans;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
        solve();
    
    return 0;
}