/* https://cses.fi/problemset/task/2422 */

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

bool check(int mid, int n){
    int count=0;
    for(int i=1; i<=n; i++){
        count+= min(n, mid/i);
    }
    return count>=((n*n)/2)+1;
}

void solve(){
    int n; cin>>n;

    int left=1, right=n*n;
    int ans=1;
    while(left<right-1){
        int mid=(left+right)/2;
        if(check(mid, n)){
            right=mid;
            ans=mid;
        }else left=mid;
    }
    cout<<ans<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    solve();

    return 0;
}