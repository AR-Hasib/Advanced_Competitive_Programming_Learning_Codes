/* https://codeforces.com/contest/279/problem/B */

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
    int n, time; cin>>n>>time;
    vector<int>v(n);
    for(auto &i:v) cin>>i;

    int i=0, j=0, ans=0, curr=0;
    while(j<n){
        while(curr+v[j]<=time && j<n){
            curr+=v[j];
            // cout<<curr<<" "<<j<<" "<<i<<endl;
            ans= max(ans, j-i+1);
            j++;
        }
        curr-=v[i];
        i++;
    }
    cout<<ans<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
        solve();
    
    return 0;
}