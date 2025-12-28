/* https://codeforces.com/problemset/problem/1547/D */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    vector<int>y(n, 0);
    for(int j=0; j<30; j++){
        bool bit=false;
        for(int i=0; i<n; i++){
            if((arr[i]&(1<<j)) && bit==false) bit=true;
            else if((arr[i]&(1<<j))==0 && bit==true) y[i]+=(1<<j);
        }
    }
    for(auto i:y) cout<<i<<" ";
    cout<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}