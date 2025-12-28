/* https://codeforces.com/problemset/problem/1671/D */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n, x; cin>>n>>x;
    int arr[n], mn=INT_MAX, mx=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        mn= min(mn, arr[i]);
        mx= max(mx, arr[i]);
    }

    ll sum=0;
    for(int i=1; i<n; i++) sum+= abs(arr[i-1]-arr[i]); // calculate initial sum

    if(mn>1){
        ll sum1= sum+ min(abs(arr[0]-1) , abs(arr[n-1]-1)); // checking the minimum, if i place the 1 in front or back
        for(int i=1; i<n; i++){ // if i place 1 in between
            sum1= min(sum1, (sum- abs(arr[i]-arr[i-1]) + abs(arr[i-1]-1) + abs(arr[i]-1)));
        }
        sum=sum1;
    }
    if(mx<x){
        ll sum1= sum+ min(abs(arr[0]-x) , abs(arr[n-1]-x)); // same thing for the maximum element
        for(int i=1; i<n; i++){
            sum1= min(sum1, (sum- abs(arr[i]-arr[i-1]) + abs(arr[i-1]-x) + abs(arr[i]-x)));
        }
        sum=sum1;
    }
    cout<<sum<<endl;
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