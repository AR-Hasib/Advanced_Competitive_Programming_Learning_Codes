/* https://codeforces.com/problemset/problem/1183/D */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ll long long
#define ld long double
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define precision fixed<<setprecision

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n; cin>>n;
    map<int, int> mp;
    while(n--){
        int x; cin>>x;
        mp[x]++;
    }

    vector<int> v;
    for(auto i:mp) v.push_back(i.second);

    sort(v.begin(), v.end());
    int m = v.size();
    int want = v[m-1], ans=0;
    int i = m-1;
    while (want>0 && i>=0){
        if(v[i]>=want && i>=0){
            ans += want;
            i--;
        }
        want--;
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