/* https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/J */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

ll solve(int n){
    if(n==1) return 1;
    return n*solve(n-1);
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    cout<<solve(tc);
    return 0;
}