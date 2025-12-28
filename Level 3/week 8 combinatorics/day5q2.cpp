/* https://codeforces.com/problemset/problem/453/A */

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

const int MOD = 1e9 + 7;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    ld m, n; cin>>m>>n;;

    ld ans=m;

    for(ld i=m-1; i>=1; i--){
        ans -= pow(i/m, n);
    }

    cout<<precision(6)<<ans<<endl;

    return 0;
}