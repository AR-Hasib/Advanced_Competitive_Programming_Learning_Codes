/* https://codeforces.com/problemset/problem/1623/C */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

bool check(vector<int>&a, int n, int mid){
    auto v=a;

    for(int i=n-1; i>1; i--){
        if(v[i]<mid) return false;
        int extra= min(v[i]-mid, a[i]);
        extra/=3;
        v[i]-=3*extra;
        v[i-1]+=extra;
        v[i-2]+=2*extra;
    }
    for(auto i:v) if(i<mid) return false;
    return true;
}

void solve(){
    int n; cin>>n;
    vector<int>a(n);
    for(auto &i:a) cin>>i;

    int left=0, right=1e9, ans=0;
    while(left<=right){
        int mid=(left+right)/2;

        if(check(a, n, mid)){
            ans=mid;
            left=mid+1;
        }else right=mid-1;
    }
    cout<<ans<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}