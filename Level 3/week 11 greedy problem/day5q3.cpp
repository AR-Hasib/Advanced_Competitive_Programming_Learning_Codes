/* https://codeforces.com/problemset/problem/898/D */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define int long long
#define ld long double
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define precision fixed<<setprecision
#define toLDouble static_cast<long double>

void solve(){
    int n, m, k; cin>>n>>m>>k;
    vector<int> v(n);
    for(auto &i:v) cin>>i;

    sort(v.begin(), v.end());
    int count=0;
    deque<int> dq;
    for(int i=0; i<n; i++){
        int x=v[i];
        dq.push_back(x);
        while(dq.front()+m <= x){
            dq.pop_front();     // adjusting window size
        }

        while(dq.size() >= k){
            dq.pop_back();      // stopping the alarm
            count++;
        }
    }
    cout<<count;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}