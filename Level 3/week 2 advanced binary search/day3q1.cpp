/* https://codeforces.com/contest/474/problem/B */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

bool found(int arr[], int mid, int worm){
    return arr[mid]<worm;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(i!=0) arr[i]+=arr[i-1];
    }
    int m; cin>>m;
    while(m--){
        int worm; cin>>worm;
        int ans=-1, left=0, right=n-1;
        while(left<=right){
            int mid=(left+right)/2;

            if(found(arr, mid, worm)){
                ans=mid;
                left=mid+1;
            }else right=mid-1;
        }
        cout<<ans+2<<endl;
    }
    
    return 0;
}