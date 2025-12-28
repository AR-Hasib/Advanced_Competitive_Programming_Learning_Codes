/* https://codeforces.com/problemset/problem/1850/F */

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
    int n; cin>>n;
    vector<int> v(n, 0);
    for(int i=0; i<n; i++) cin>>v[i];
    map<int, int> frog;
    for(auto i:v) frog[i]++;

    vector<int>trapped(n+1, 0);
    for(auto i:frog){
        for(int j=i.first; j<=n; j+=i.first){
            trapped[j]+= i.second;
        }
    }

    int ans=0;
    for(auto i:trapped) ans=max(ans, i);
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