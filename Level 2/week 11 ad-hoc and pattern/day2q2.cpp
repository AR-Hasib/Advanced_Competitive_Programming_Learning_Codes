/* https://codeforces.com/contest/1819/problem/A */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

int findMex(int arr[], int n){
    map<int, int> mp;
    for(int i=0; i<n; i++) mp[arr[i]]++;
    int mex=0;
    for(auto i:mp){
        if(i.first==mex) mex++;
    }
    return mex;
}

void solve(){
    int n; cin>>n;
    int arr[n];
    map<int, int> freq;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        freq[arr[i]]++;
    }

    int mex= findMex(arr, n);
    int target= mex+1;

    int l=-1, r=-1;
    for(int i=0; i<n; i++){
        if(arr[i]==target){
            if(l==-1) l=i;
            r=i;
        }
    }

    if(l!=-1){
        for(int i=l; i<=r; i++) arr[i]=mex;
        if(findMex(arr, n)==target) yes;
        else no;
        return;
    }else{
        for(auto i:freq){
            if(i.first<mex && i.second>1){
                yes; return;
            }
            if(i.first>target){
                yes; return;
            }
        }
        no; return;
    }
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}