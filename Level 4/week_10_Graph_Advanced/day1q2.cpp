/* https://codeforces.com/contest/17/problem/B */

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
#define setAll(x, y) memset(x, y, sizeof(x))
#define printVector(vctr) for(auto &vlu:vctr) cout<<vlu<<" "; cout<<endl;
#define VV(x) vector<vector<x>>

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<int> quality(n);
    for(auto &i:quality) cin>>i;

    vector<vector<pair<int, int>>> edges(n);
    int eq; cin>>eq;
    while(eq--){
        int u, v, w; cin>>u>>v>>w;
        u--, v--;

        // who wants to become supervisor of ith person
        edges[v].push_back({w, u});
    }

    int count = 0;
    for(int i=0; i<n; i++){
        if(edges[i].size() == 0) count++;
    }

    if(count>1) cout<<-1<<endl;
    else{
        // we will choose the min cost supervisor for each person

        int cost = 0;
        for(auto &ed:edges){
            int mn = INT_MAX;
            for(auto [wt, u]:ed){
                mn = min(mn, wt);
            }
            if(mn != INT_MAX) cost+=mn;
        }
        cout<<cost<<endl;
    }
    
    return 0;
}