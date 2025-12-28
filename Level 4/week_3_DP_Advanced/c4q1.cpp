/* https://cses.fi/problemset/task/2181 */

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
const int INF = LLONG_MAX /2;

void generateTransition(int index, int mask1, int mask2, int n, vector<vector<int>> &transition){
    // if we run outside 
    if(index > n){
        return;
    }

    // when we reach exactly n
    if(index == n){
        transition[mask1].push_back(mask2);
        return;
    }

    // case 1: current block is 1 in mask1
    generateTransition(index+1, mask1 | 1<<index, mask2, n, transition);
    // case 2a: current block is 0 in mask1
    generateTransition(index+1, mask1, mask2 | 1<<index, n, transition);
    // case 2b: current block is 0 in mask1
    generateTransition(index+2, mask1, mask2, n, transition);
}

int solveDP(int index, int mask, int m, vector<vector<int>> &dp, vector<vector<int>> &transition){
    if(index == m){
        if(mask == 0) return 1;
        return 0;
    }

    if(dp[index][mask] != -1) return dp[index][mask];

    int ans = 0;
    for(auto newMask:transition[mask]){
        ans = (ans + solveDP(index+1, newMask, m, dp, transition))%MOD;
    }
    return dp[index][mask] = ans;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin>>n>>m;
    int totalMask = 1<<n;
    vector<vector<int>> dp(m+1, vector<int>(totalMask, -1));
    vector<vector<int>> transition(totalMask);
    generateTransition(0, 0, 0, n, transition);

    // for(auto i:transition){
    //     for(auto j:i) cout<<j<<" ";
    //     cout<<endl;
    // }
    
    cout<<solveDP(0, 0, m, dp, transition)<<endl;

    return 0;
}