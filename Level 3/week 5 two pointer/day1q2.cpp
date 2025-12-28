/* https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/E */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n, k; cin>>n>>k;
    vector<int>v(n);
    for(auto &i:v) cin>>i;

    if(k==0){
        cout<<0;
        return;
    }

    map<int, int>mp;
    ll ans=0;
    int j=0;
    for(int i=0; i<n; i++){
        while(j<n){
            mp[v[j]]++; 
            if(mp.size()>k){
                mp[v[j]]--;
                if(mp[v[j]]==0) mp.erase(v[j]); 
                break;
            }
            j++; 
        }       

        ans+= (j-i);
        mp[v[i]]--;
        if(mp[v[i]]==0) mp.erase(v[i]);
    }
    cout<<ans;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
        solve();
    
    return 0;
}