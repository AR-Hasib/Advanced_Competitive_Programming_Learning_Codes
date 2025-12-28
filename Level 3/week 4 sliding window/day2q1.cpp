/* https://codeforces.com/problemset/problem/1622/C */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

void solve(){
    int n, target; cin>>n>>target;
    vector<int>arr(n);
    for(auto &i:arr) cin>>i;
    sort(arr.begin(), arr.end());
    for(int i=1; i<n; i++) arr[i]+=arr[i-1];
    
    if(arr[n-1]<=target){
        cout<<0<<endl;
        return;
    }

    int ans= arr[n-1]-target;

    for(int i=n-1; i>0; i--){
        int count= n-i;     // number of element i have already traversed
        int tempTarget= target-(arr[i-1]-arr[0]);  // i want to keep (arr[1] to arr[i-1]) as they are. just want to change arr[i] to last and the arr[0]. and they will be same
        int x= tempTarget/(count+1);    // x is the value what the changed elements has to be. ==> count+ 1(arr[0])
        if(tempTarget<0 && tempTarget%(count+1)) x--;   // in negative number cpp give us ceil instead of floor
        int temp=count;     // 2nd operations need
        if(x<arr[0]) temp+=arr[0]-x;     // 1st operations
        ans= min(ans, temp);
    }

    cout<<ans<<endl;
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}