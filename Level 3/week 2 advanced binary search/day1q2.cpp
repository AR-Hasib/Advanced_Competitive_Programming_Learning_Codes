/* https://cses.fi/problemset/task/1620 */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

bool possible(int arr[], int n, int time, int products){
    int total=0;
    for(int i=0; i<n; i++){
        total+= time/arr[i];
        if(total>=products) return true;
    }
    return total>=products;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, products; cin>>n>>products;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int left=1, right=1e18; // as i don't know the actual left and right limit, i assume here
    int ans=-1;
    while(left<=right){
        int mid= (left+right)/2;

        if(possible(arr, n, mid, products)){
            ans=mid;
            right=mid-1;
        }else left=mid+1;
    }

    cout<<ans<<endl;

    return 0;
}