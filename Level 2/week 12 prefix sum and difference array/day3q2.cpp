/* https://cses.fi/problemset/task/1662 */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    map<int, int>mp;
    mp[0]=1;
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        mp[((sum%n)+n)%n]++;
    }

    int ans=0;
    for(auto it:mp){
        ans+=(it.second * (it.second-1))/2;
    }
    cout<<ans<<endl;

    return 0;
}