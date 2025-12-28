/* https://codeforces.com/contest/1881/problem/D */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n; cin>>n;
    map<int, int>div;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        for(int j=2; j*j<=x; j++){
            if(x%j==0){
                while(x%j==0){
                    x/=j;
                    div[j]++;
                }
            }
        }
        if(x>1) div[x]++;
    }

    for(auto it:div){
        if(it.second%n != 0){
            no;
            return;
        }
    }
    yes;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}