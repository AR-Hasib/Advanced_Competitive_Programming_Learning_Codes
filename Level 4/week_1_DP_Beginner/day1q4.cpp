/* https://cses.fi/problemset/task/1634 */

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
#define toLDouble static_cast<long double>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, x; cin>>n>>x;
    vector<int> coins(n);
    for(auto &i:coins) cin>>i;

    vector<int> dp(x+1, 1e9);
    dp[0]=0;

    for(int i=1; i<=x; i++){
        for(auto coin:coins){
            if(coin<=i){
                dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
    }

    cout<<(dp[x]==1e9 ? -1:dp[x])<<endl;

    return 0;
}