/* https://codeforces.com/problemset/problem/1520/F1 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

int query(int temp){
    cout<<"? "<<1<<" "<<temp<<endl;
    int x; cin>>x;
    return x;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, t, k; cin>>n>>t>>k;

    int ans=-1;
    int left=1, right=n;

    while(left<=right){
        int mid= (left+right)/2;
        int sum=query(mid);

        if(sum+k <= mid){
            ans=mid;
            right= mid-1;
        }else left= mid+1;
    }

    cout<<"! "<<ans<<endl;

    return 0;
}