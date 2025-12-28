/* https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/C */

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

void solve(){
   int n, r; cin>>n>>r;
   vector<int>v(n);
   for(auto &i:v) cin>>i;

   int ans=0, i=0, j=1;
   int currDistance=v[j]-v[i];
   while(j<n){
        while(currDistance<=r && j<n){
            j++;
            if(j<n) currDistance=v[j]-v[i];
        }
        ans+=(n-j);
        i++;
        currDistance=v[j]-v[i];
   }
   cout<<ans<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    solve();
    return 0;
}