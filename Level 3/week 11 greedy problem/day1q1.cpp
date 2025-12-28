/* https://cses.fi/problemset/task/2183 */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define int long long
#define ld long double
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define precision fixed<<setprecision

void solve(){
    int n; cin>>n;
    vector<int> v(n);
    for(auto &i:v) cin>>i;

    sort(v.begin(), v.end());
    if(v[0]!=1) cout<<1<<endl;
    else{
        int minCoinSum=0;
        int maxCoinSum=1;

        for(int i=1; i<n; i++){
            int newMax = maxCoinSum+v[i];
            if(v[i]-maxCoinSum > 1){
                break;
            }
            maxCoinSum = newMax;
        }
        cout<<maxCoinSum+1<<endl;
    }
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}