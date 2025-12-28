/* https://codeforces.com/problemset/problem/1698/D */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

int query(int start, int end){
    cout<<"? "<<start<<" "<<end<<endl;
    
    int count=0;
    for(int i=start; i<=end; i++){
        int x; cin>>x;
        if(start<=x && x<=end) count++;
    }

    return count%2;
}

void solve(){
    int n; cin>>n;
    int left=1, right=n;
    int ans=-1;

    while(left<=right){
        int mid= (left+right)/2;

        if(query(left, mid)){
            ans=mid;
            right=mid-1;
        }else left=mid+1;
    }

    cout<<"! "<<ans<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }

    return 0;
}