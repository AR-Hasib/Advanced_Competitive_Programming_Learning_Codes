/* https://codeforces.com/problemset/problem/1722/G */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

void solve(){
    int n; cin>>n;

    if(n==3) cout<<"2 1 3";
    else if(n%4==0){
        int add=(1ll<<30);
        int curr=1;
        for(int i=1; i<=n/2; i++){
            cout<<curr<<" "<<curr+add<<" ";
            curr++;
        }
    }else if(n%2==1){
        int add0=(1ll<<25);
        int add1=(1ll<<26);
        cout<<add1<<" ";
        int curr=1;
        for(int i=1; i<(n/2); i++){
            cout<<curr<<" "<<curr+add0<<" ";
            curr++;
        }
        if((n/2)%2==0) cout<<curr<<" "<<curr+add0+add1;
        else cout<<curr<<" "<<curr+add1;
    }else{
        int add0=(1ll<<25);
        int add1=(1ll<<26);
        cout<<0<<" "<<add1<<" ";
        int curr=1;
        for(int i=1; i<=(n/2)-2; i++){
            cout<<curr<<" "<<curr+add0<<" ";
            curr++;
        }
        cout<<curr<<" "<<curr+add0+add1;
    }
    cout<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}