/* https://cses.fi/problemset/task/1631 */

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

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n; 
    int mx=0, sum=0;
    while(n--){
        int x; cin>>x;
        sum += x;
        mx = max(mx, x);
    }

    if(mx*2 > sum) cout<<mx*2<<endl;
    else cout<<sum<<endl;

    return 0;
}