/* https://codeforces.com/problemset/problem/152/C */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

void solve(){
    int n, m; cin>>n>>m;
    vector<string> v(n);
    for(auto &i:v) cin>>i;

    int ans=1;
    for(int i=0; i<m; i++){
        unordered_set<char>s;
        for(auto j:v) s.insert(j[i]);

        int unique_char = s.size();
        ans = (ans * unique_char)%MOD;
    }

    cout<<ans<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}