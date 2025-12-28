/* https://codeforces.com/problemset/problem/1166/C */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<int>arr(n); 
    for(int i=0; i<n; i++){
        cin>>arr[i];
        arr[i]=abs(arr[i]);
    }
    sort(arr.begin(), arr.end());

    int ans=0;
    for(int i=0; i<n; i++){
        int temp= upper_bound(arr.begin(), arr.end(), 2*arr[i])-arr.begin();
        temp--;
        ans+= temp-i;
    }

    cout<<ans<<endl;

    return 0;
}