/* https://codeforces.com/contest/433/problem/B */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    int arr[n], sortArr[n];
    for(int i=0; i<n; i++){ 
        cin>>arr[i];
        sortArr[i]=arr[i];
        if(i!=0) arr[i]+=arr[i-1];
    }

    sort(sortArr, sortArr+n);
    for(int i=1; i<n; i++) sortArr[i]+=sortArr[i-1];

    int tc; cin>>tc;
    while(tc--){
        int type, l, r; cin>>type>>l>>r;
        l--; r--;
        if(type==1){
            if(l==0) cout<<arr[r]<<endl;
            else cout<<arr[r]-arr[l-1]<<endl;
        }else{
            if(l==0) cout<<sortArr[r]<<endl;
            else cout<<sortArr[r]-sortArr[l-1]<<endl;
        }
    }
    return 0;
}