/* https://codeforces.com/contest/1633/problem/D */

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
#define toLDouble static_cast<long double>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

// tabulaton with space optimization [taken from knapsack problem]
int tabSpSolve(vector<int> &weight, vector<int> &value, int n, int maxCapacity, vector<int> &dp){
    for(int i=weight[0]; i<=maxCapacity; i++){
        dp[i] = value[0];
    }

    for(int item=1; item<n; item++){
        for(int cap=maxCapacity; cap>=0; cap--){
            int include = 0;
            if(weight[item] <= cap){
                include = value[item] + dp[cap-weight[item]];
            }
            int skip = dp[cap];

            dp[cap] = max(include, skip);
        }
    }
    return dp[maxCapacity];
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int N=1001;
    vector<int> req(N, 1e9);
    req[1]=0;
    for(int i=1; i<=N; i++){
        for(int x=1; x<=i; x++){
            int j = i+(i/x);
            if(j<N) req[j] = min(req[j], req[i]+1);
        }
    }

    int tc; cin>>tc;
    while(tc--){
        int n, k; cin>>n>>k;
        vector<int> b(n), c(n);
        for(auto &i:b) cin>>i;
        for(auto &i:c) cin>>i;

        for(int i=0; i<n; i++){
            b[i] = req[b[i]];
        }

        // k = min(k, 12*n);
        vector<int>dp(k+1, 0);
        cout<<tabSpSolve(b, c, n, k, dp)<<endl;
    }
    return 0;
}