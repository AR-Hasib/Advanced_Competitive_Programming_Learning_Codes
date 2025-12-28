/* https://codeforces.com/problemset/problem/1225/B2*/

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
    int n, k, d; cin>>n>>k>>d;
    vector<int>v(n);
    for(auto &i:v) cin>>i;

    int ans=INT_MAX;
    map<int, int>m;
    int i=0, j=0;
    while(j<d-1){
        m[v[j]]++;
        j++;
    }
    while(j<n){
        m[v[j]]++;
        ans= min(ans, int(m.size()));
        m[v[i]]--;
        if(m[v[i]]==0) m.erase(v[i]);
        i++;
        j++;
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