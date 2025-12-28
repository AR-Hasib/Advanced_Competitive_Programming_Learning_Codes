/* https://codeforces.com/problemset/problem/1202/A */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
string x, y; cin>>x>>y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    int a=0, b=0;
    for(int i=0; i<y.length(); i++){
        if(y[i]=='1'){
            a=i;
            break;
        }
    }
    for(int i=a; i<x.length(); i++){
        if(x[i]=='1'){
            b=i;
            break;
        }
    }
    cout<<b-a<<endl;

}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}