/* https://codeforces.com/problemset/problem/1419/D2 */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

bool check(vector<int>&arr, int n, int mid){
    for(int i=mid-1, j=n-1; i>=0; i--, j--){
        if(!(arr[i]<arr[j] && arr[i]<arr[j-1])) return false;
    }
    return true;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n; 
    vector<int>arr(n, 0);
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr.begin(), arr.end());
    int ans=0;

    int left=1, right=(n+1)/2-1;
    while(left<=right){
        int mid=(left+right)/2;

        if(check(arr, n, mid)){
            left=mid+1;
            ans=mid;
        }else right= mid-1;
    }

    cout<<ans<<endl;

    int j=n-1;
    for(int i=ans-1; i>=0; i--, j--){
        cout<<arr[j]<<" "<<arr[i]<<" ";
    }

    while(j>ans-1){
        cout<<arr[j]<<" ";
        j--;
    }

    return 0;
}