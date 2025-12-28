/* https://codeforces.com/problemset/problem/702/C */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

bool check(vector<int>city, vector<int>tower, int n, int m, int r){
    int i=0, j=0;
    while(i<n && j<m){
        if(abs(city[i]-tower[j])<=r) i++;
        else j++;
    }

    return i==n;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin>>n>>m;
    vector<int>city(n), tower(m);
    for(int i=0; i<n; i++) cin>>city[i];
    for(int i=0; i<m; i++) cin>>tower[i];

    int ans=-1;
    int left=0, right=1e16;
    while(left<=right){
        int mid= (left+right)/2;

        if(check(city, tower, n, m, mid)){
            ans=mid;
            right=mid-1;
        }
        else left=mid+1;
    }

    cout<<ans<<endl;

    return 0;
}