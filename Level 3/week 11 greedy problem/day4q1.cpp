/* https://codeforces.com/problemset/problem/620/C */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ll long long
#define ld long double
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define precision fixed<<setprecision

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n; cin>>n;
    vector<int> v(n);
    for(auto &i:v) cin>>i;

    vector<pair<int, int>> segment;
    int i=0, j=0;
    while(j<n){
        map<int, int> mp;
        while(j<n){
            mp[v[j]]++;
            if(mp[v[j]]==2){
                segment.push_back({i+1, j+1});
                break;
            }
            j++;
        }
        j++;
        i=j;
    }

    if(segment.size()){
        int m = segment.size();
        cout<<m<<endl;
        for(int i=0; i<m; i++){
            if(i==m-1){
                cout<<segment[i].first<<" "<<max(segment[i].second, n)<<endl;
            }else{
                cout<<segment[i].first<<" "<<segment[i].second<<endl;
            }
        }
    }else{
        cout<<-1<<endl;
    }
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}