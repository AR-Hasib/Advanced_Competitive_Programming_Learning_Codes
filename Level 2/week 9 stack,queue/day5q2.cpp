/* https://codeforces.com/problemset/problem/1179/A */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    ll n, q; cin>>n>>q;
    deque<ll>arr(n);
    for(ll i=0; i<n; i++) cin>>arr[i];

    vector<pair<ll, ll>>ans;
    for(ll i=0; i<n-1; i++){
        ll a=arr[0];
        arr.pop_front();
        ll b=arr[0];
        arr.pop_front();
        ans.push_back({a,b});

        if(a>b){
            arr.push_front(a);
            arr.push_back(b);
        }else{
            arr.push_back(a);
            arr.push_front(b);
        }
    }

    while(q--){
        ll m; cin>>m;
        m--;
        if(m<n-1){
            cout<<ans[m].first<<" "<<ans[m].second<<endl;
        }else{
            ll pos=(m%(n-1));
            cout<<arr[0]<<" "<<arr[pos+1]<<endl;
        }
    }

    return 0;
}