/* https://cses.fi/problemset/task/1085 */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

bool possible(int arr[], int n, int limit, int divison){
    int sub=1;
    int curr=0;
    for(int i=0; i<n; i++){
        if(curr+arr[i]>limit){
            curr=0;
            sub++;
        }
        curr+=arr[i];
        if(sub>divison) break;
    }
    return sub<=divison;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, divison; cin>>n>>divison;
    int arr[n];
    int mx=0, sum=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        mx=max(mx, arr[i]);
        sum+=arr[i];
    }

    // maximum element is left bound and total sum is right bound
    int ans=-1;
    while(mx<=sum){
        int mid= (mx+sum)/2;

        if(possible(arr, n, mid, divison)){
            ans=mid;
            sum=mid-1;
        }else mx=mid+1;
    }

    cout<<ans<<endl;

    return 0;
}