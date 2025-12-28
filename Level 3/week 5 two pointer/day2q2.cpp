/* https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/F */

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
    int n, k; cin>>n>>k;
    vector<int>v(n);
    for(auto &i:v) cin>>i;

    int mn=INT_MAX, mx=INT_MIN;
    multiset<int>ms;
    int ans=0, i=0, j=0;
    
    while(j<n){
        ms.insert(v[j]);
        mx=*(--ms.end());
        mn=*(ms.begin());

        while(i<=j && mx-mn>k){
            ms.erase(ms.find(v[i]));
            mx=*(--ms.end());
            mn=*(ms.begin());
            i++;
        }
        ans+=j-i+1;
        j++;
    }
    cout<<ans;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    solve();

    return 0;
}