/* https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

int solve(int i, int left, int n, int weight[], int value[]){
    if(i==n) return 0;

    if(left>=weight[i]) 
        return max(solve(i+1, left, n, weight, value), solve(i+1, left-weight[i], n, weight, value)+value[i]);
    else return solve(i+1, left, n, weight, value);
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k; cin>>n>>k;
    int weight[n], value[n];
    for(int i=0; i<n; i++){
        cin>>weight[i];
        cin>>value[i];
    } 
    cout<<solve(0, k, n, weight, value);
    return 0;
}