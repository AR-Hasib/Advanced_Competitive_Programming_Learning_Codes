/* https://cses.fi/problemset/task/1097 */

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

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<int> a(n);
    for(auto &i:a) cin>>i;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    /* dp[i][j] = maximum score 1st player can score when
    the left element is a[i] and the right element is a[j] */

    auto solve = [&] (auto &&solve, int i, int j) -> int{
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int x = a[i] + min(solve(solve, i+2, j), solve(solve, i+1, j-1));
        int y = a[j] + min(solve(solve, i+1, j-1), solve(solve, i, j-2));
        return dp[i][j] = max(x, y);
    };

    cout<<solve(solve, 0, n-1)<<endl;

    return 0;
}