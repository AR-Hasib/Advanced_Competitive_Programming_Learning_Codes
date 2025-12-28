/* https://codeforces.com/problemset/problem/1362/B */

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
    vector<int>temp(1024, 0);
    for(int i=0; i<n; i++) temp[arr[i]]++;
    
    int ans=-1;
    for(int k=1; k<1024; k++){
        vector<int>v(1024, 0);
        for(int i=0; i<n; i++) v[arr[i]^k]++;

        bool flag=true;
        for(int i=0; i<1024; i++){
            if(temp[i]!=v[i]){
                flag=false;
                break;
            }
        }
        if(flag){
            ans=k;
            break;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}