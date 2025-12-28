/* https://codeforces.com/problemset/problem/1567/B */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;



void solve(int arr[]){
    int a, b; cin>>a>>b;
    if(arr[a-1]==b) cout<<a<<endl;
    else if((arr[a-1]^b)==a) cout<<a+2<<endl;
    else cout<<a+1<<endl;
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);

    int arr[300000];
    arr[0]=0;
    for(int i=1; i<300000; i++) arr[i]=(arr[i-1]^i);

    int tc; cin>>tc;
    while(tc--){
        solve(arr);
    }
    return 0;
}