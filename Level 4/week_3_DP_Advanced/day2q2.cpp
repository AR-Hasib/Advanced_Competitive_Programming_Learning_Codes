/* https://codeforces.com/contest/19/problem/B */

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
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;
const int INF = 1e15;

void solve(){
    int n; cin>>n;
    vector<int> time(n), cost(n);
    for(int i=0; i<n; i++){
        int x; cin>>x>>cost[i];
        time[i] = x+1;
    }
    /* we are increasing time by 1. now we can say we are buying this
    1 ith item and stealing time[i]-1 item. as we have total n item,
    our goal is now to make the total_time>=n where cost is minimum*/
    
    /* dp[i][j] = minimum cost to fillup j time with the items 0th....ith.*/
    int m = n+2000; // worst case when we have just 1 item and its time is 2000
    vector<int> curr(m, INF), pre(m, INF);
    pre[0] = curr[0] = 0;
    for(int i=0; i<n; i++){
        for(int j=1; j<m; j++){
            int take = INF;
            if(time[i] <= j) take = cost[i] + pre[j - time[i]];
            int skip = pre[j];
            curr[j] = min(skip, take);
        }
        pre = curr;
    }

    int mnCost = INF;
    for(int i=n; i<m; i++) mnCost = min(mnCost, curr[i]);
    cout<<mnCost<<endl;

    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}