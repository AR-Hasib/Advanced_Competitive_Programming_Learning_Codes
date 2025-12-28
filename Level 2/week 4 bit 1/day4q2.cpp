/* https://codeforces.com/problemset/problem/1742/G */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

void solve(){
    int n; cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    vector<int>ans;
    int curr=0;
    for(int i=0; i<min(n, 32ll); i++){
        int best=curr;
        int idx=-1;
        for(int j=0; j<n; j++){
            if(arr[j]!=-1){
                if((curr|arr[j])>=best){
                    best=(curr|arr[j]);
                    idx=j;
                }
            }
        }
        if(best>curr){
            ans.push_back(arr[idx]);
            arr[idx]=-1;
            curr=best;
        }
    }

    for(int i=0; i<n; i++){
        if(arr[i]!=-1) ans.push_back(arr[i]);
    }
    for(auto i:ans) cout<<i<<" ";
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