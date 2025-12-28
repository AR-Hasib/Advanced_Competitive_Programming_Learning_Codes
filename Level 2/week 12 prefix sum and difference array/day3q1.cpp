/* https://cses.fi/problemset/task/1652 */

// 2D Prefix Sum

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, q; cin>>n>>q;
    int arr[n][n];
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0; j<n; j++){
            if(s[j]=='.') arr[i][j]=0;
            else arr[i][j]=1;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0) continue;

            if(i==0) arr[i][j]+=arr[i][j-1]; // 1st row
            else if(j==0) arr[i][j]+=arr[i-1][j]; // 1st column
            else arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]; // other index
        }
    }

    while(q--){
        int a, b, c, d; cin>>a>>b>>c>>d;
        a--; b--; c--; d--;

        int ans=arr[c][d];
        if(a-1>=0) ans-= arr[a-1][d];
        if(b-1>=0) ans-= arr[c][b-1];
        if(a-1>=0 && b-1>=0) ans+= arr[a-1][b-1];

        cout<<ans<<endl;
    }
    return 0;
}