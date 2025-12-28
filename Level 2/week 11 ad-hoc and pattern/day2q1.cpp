/* https://codeforces.com/contest/1821/problem/B */

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
    int arr[n], brr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<n; i++) cin>>brr[i];

    int left, right;
    bool flag=false;
    for(int i=0; i<n; i++){
        if(arr[i]==brr[i]) continue;
        
        if(!flag) left=i;
        flag=true;
        right=i;
    }

    while(brr[left-1]<=brr[left] && left>0) left--;
    while(brr[right+1]>=brr[right] && right<n-1) right++;

    cout<<left+1<<" "<<right+1<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}