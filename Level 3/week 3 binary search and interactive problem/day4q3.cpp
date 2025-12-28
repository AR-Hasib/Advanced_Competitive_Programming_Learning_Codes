/* https://codeforces.com/problemset/problem/1610/C */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

bool check(vector<int>& a, vector<int>& b, int n, int want){
    int invited=0;
    for(int i=1; i<=n; i++){
        if((a[i]>=(want-invited-1)) && (b[i]>=invited)) invited++;
    
        if(invited>=want) return true;
    }
    return invited>=want;
}

void solve(){
    int n; cin>>n;
    vector<int> a(n+1, 0), b(n+1, 0);
    for(int i=1; i<=n; i++){
        cin>>a[i]>>b[i];
    }

    int left=1, right=n, ans=-1;
    while(left<=right){
        int mid= (left+right)/2;

        if(check(a, b, n, mid)){
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