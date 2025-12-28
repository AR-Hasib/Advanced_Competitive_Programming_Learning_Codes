/* https://codeforces.com/problemset/problem/1873/F */

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
    int n,k; cin>>n>>k;
    vector<int>a(n);
    vector<int>h(n);
    for(auto &i:a) cin>>i;
    for(auto &i:h) cin>>i;

    int curr=a[0], ans=0;
    int i=0, j=0;
    while(j<n){
        while(j<n-1 && (h[j]%h[j+1]==0) && curr+a[j+1]<=k){
            curr+=a[j+1];
            j++;
        }
        if(curr<=k) ans= max(ans, j-i+1);
        curr-=a[i];
        i++;
        if(i>j){
            j=i;
            if(j<n) curr=a[j];
        }
    }
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