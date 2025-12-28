/* https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/N */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;
int l=0;

void pt(int arr[], int brr[], int r, int c, int l){
    if(l%c==0 && l!=0) cout<<endl;
    cout<<arr[l]+brr[l]<<" ";
    if(l<r*c-1) pt(arr, brr, r, c, l+1);
}

void solve(){
    int r, c; cin>>r>>c;
    int arr[r*c], brr[r*c];
    for(int i=0; i<r*c; i++) cin>>arr[i];
    for(int i=0; i<r*c; i++) cin>>brr[i];
    pt(arr, brr, r, c, 0);
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    solve();
    return 0;
}