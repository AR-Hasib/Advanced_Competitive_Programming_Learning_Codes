/* https://codeforces.com/problemset/problem/1726/B */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n, m; cin>>n>>m;
    if(n>m) no;
    else{
        if(m%2){
            if(n%2){
                yes;
                for(int i=0; i<n-1; i++) cout<<1<<" ";
                cout<<m-n+1<<endl;
            }else no;
        }else{
            yes;
            if(n%2){
                for(int i=0; i<n-1; i++) cout<<1<<" ";
                cout<<m-n+1<<endl;
            }else{
                for(int i=0; i<n-2; i++) cout<<1<<" ";
                cout<<(m-n+2)/2<<" "<<(m-n+2)/2<<endl;
            }
        }
    }
    
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}