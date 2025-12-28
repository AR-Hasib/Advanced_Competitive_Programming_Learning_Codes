/* https://codeforces.com/problemset/problem/844/B */

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

void solve(){
   int n, m; cin>>n>>m;
   int arr[n][m];

   for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
   }

   int ans=0;
   for(int i=0; i<n; i++){  // going rows
        int count=0;
        for(int j=0; j<m; j++) count+=arr[i][j];
        ans += (1ll<<count) -1;
        ans += (1ll<<(m-count)) -1;
   }

   for(int i=0; i<m; i++){  // colums
        int count=0;
        for(int j=0; j<n; j++) count+=arr[j][i];
        ans += (1ll<<count) -1;
        ans += (1ll<<(n-count)) -1;
   }

   cout<<ans-(m*n)<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc = 1;
    while(tc--){
        solve();
    }
    return 0;
}