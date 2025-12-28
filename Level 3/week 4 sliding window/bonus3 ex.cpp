/* https://codeforces.com/contest/1600/problem/E */

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

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    
    int l=0, r=n-1;
    while(l+1){
        if(a[l]<a[l+1]) l++;
        else break;
    }

    while(r){
        if(a[r-1]>a[r]) r--;
        else break;
    }

    if((n-r)&1||(l+1)&1){
        cout<<"Alice"<<endl;
        return ;
    }
    cout<<"Bob"<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    solve();

    return 0;
}