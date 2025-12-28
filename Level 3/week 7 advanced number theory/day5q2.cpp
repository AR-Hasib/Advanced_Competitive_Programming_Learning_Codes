/* https://atcoder.jp/contests/abc169/tasks/abc169_d */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin>>n;
    int ans=0;

    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            int count=0, m=0;
            while(n%i==0){
                n/=i;
                count++;
            }
            while((m*(m+1))/2 <= count) m++;
            ans += m-1;
        }
    }
    cout<<ans + (n>1)<<endl; // if n>1 it will add 1 else 0
    
    return 0;
}