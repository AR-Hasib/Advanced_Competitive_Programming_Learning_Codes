/* https://codeforces.com/contest/876/problem/B */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ll long long
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n, k, m; cin>>n>>k>>m;
    vector<int>v(n);
    for(auto &i:v) cin>>i;

    map<int, int>mp;
    int mod=-1; bool flag=false;
    for(int i=0; i<n; i++){
        mp[v[i]%m]++;
        if(mp[v[i]%m]>=k){
            yes; 
            flag=true; 
            mod=v[i]%m;
            break;
        }
    }
    if(flag){
        while(k){
            for(int i=0; i<n; i++){
                if(v[i]%m==mod){
                    cout<<v[i]<<" ";
                    k--;
                    if(!k) break;
                }
            }
        }
    }else no;
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    solve();

    return 0;
}