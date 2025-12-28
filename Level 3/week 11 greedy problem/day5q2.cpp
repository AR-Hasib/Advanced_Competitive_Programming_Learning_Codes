/* https://codeforces.com/problemset/problem/545/C */

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
#define toLDouble static_cast<long double>

void solve(){
    int n; cin>>n;
    vector<int> a(n, 0), h(n, 0);
    for(int i=0; i<n; i++) cin>>a[i]>>h[i];

    if(n==1){
        cout<<1;
        return;
    }

    int count = 2;
    for(int i=1; i<n-1; i++){
        if(a[i-1] < a[i]-h[i]){
            count++;    // fell left
        }else if(a[i]+h[i] < a[i+1]){
            count++;
            a[i]+=h[i];
        }
    }
    cout<<count<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}