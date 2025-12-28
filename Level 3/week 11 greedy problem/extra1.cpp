/* https://codeforces.com/problemset/problem/723/C */

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
    int n, m; cin>>n>>m;
    vector<int> band(n), liked(m+1, 0);
    for(auto &i:band) cin>>i;

    vector<int> can;

    for(int i=0; i<n; i++){
        if(band[i]>m) can.push_back(i);
        else{
            if(liked[band[i]]==n/m) can.push_back(i);
            else liked[band[i]]++;
        }
    }

    int count=0;
    for(int i=1; i<=m; i++){
        while(liked[i]<n/m){
            band[can.back()] = i;
            liked[i]++;
            count++;
            can.pop_back();
        }
    }

    cout<<n/m<<" "<<count<<endl;
    for(auto i:band) cout<<i<<" ";
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}