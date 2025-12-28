#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

int helper(int row, int col, int n, int m, vector<vector<int>>&v){
    if(row==n-1 && col==m-1){
        return v[row][col];
    }
    if(row<n-1){
        if(col<m-1){
            return max(helper(row, col+1, n, m, v)+v[row][col], helper(row+1, col, n, m, v)+v[row][col]);
        }
        else{
            return helper(row+1, col, n, m, v)+v[row][col];
        }
    }
    else{
        return helper(row, col+1, n, m, v)+v[row][col];
    }
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    ll n, m; cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }
    cout<<helper(0, 0, n, m, v);
    return 0;
}