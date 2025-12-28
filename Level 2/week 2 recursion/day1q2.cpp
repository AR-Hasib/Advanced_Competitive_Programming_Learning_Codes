/* https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/Q */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

vector<ll>v;

void solve(int n){
    v.emplace_back(n);
    if (n==1) return;
    else if(n%2==0) solve(n/2);
    else solve((3*n)+1);
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    solve(n);
    cout<<int(v.size());
    return 0;
}