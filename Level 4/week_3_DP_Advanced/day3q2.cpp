/* https://codeforces.com/contest/580/problem/D */

// memory limit crossed , we have think for 2D dp
// //#include <ext/pb_ds/assoc_container.hpp>
// //#include <ext/pb_ds/tree_policy.hpp>
// #include <bits/stdc++.h>
// //using namespace __gnu_pbds;
// using namespace std;
// //template<typename T>
// //using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// #define endl '\n'
// #define int long long
// #define ld long double
// #define yes cout<<"YES"<<endl
// #define no cout<<"NO"<<endl
// #define precision fixed<<setprecision
// #define toLDouble static_cast<long double>
// #define sz(x) ((int)(x).size())
// #define all(x) (x).begin(), (x).end()

// const int MOD = 1e9 + 7;
// const int INF = LLONG_MAX /2;

// int f(int index, int mask, int last, int m, int n, vector<int> &a, vector<vector<int>> &bonus, vector<vector<vector<int>>> &dp){
//     if(index == m){
//         return 0;
//     }

//     if(dp[index][mask][last+1] != -1) return dp[index][mask][last+1];

//     int ans = 0;
//     for(int i=0; i<n; i++){
//         if((mask & (1<<i)) == 0){
//             int satisfaction = a[i];
//             if(last>=0) satisfaction += bonus[last][i];
//             ans = max(ans, satisfaction + f(index+1, mask|1<<i, i, m, n, a, bonus, dp));
//         }
//     }
//     return dp[index][mask][last+1] = ans;
// }

// signed main(){
    
//     ios::sync_with_stdio(false); cin.tie(NULL);
    
//     int n, m, k; cin>>n>>m>>k;
//     vector<int> a(n);
//     for(auto &i:a) cin>>i;
//     vector<vector<int>> bonus(n, vector<int>(n, 0));

//     while(k--){
//         int a, b, c; cin>>a>>b>>c;
//         bonus[a-1][b-1] = c; // we are using 0 base indexing
//     }
//     vector<vector<vector<int>>> dp(m, vector<vector<int>>(1<<n, vector<int>(n+1, -1)));
//     cout<<f(0, 0, -1, m, n, a, bonus, dp)<<endl;

//     return 0;
// }


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

int f(int index, int mask, int last, int m, int n, vector<int> &a, vector<vector<int>> &bonus, vector<vector<int>> &dp){
    if(index == m){
        return 0;
    }

    if(dp[mask][last+1] != -1) return dp[mask][last+1];

    int ans = 0;
    for(int i=0; i<n; i++){
        if((mask & (1<<i)) == 0){
            int satisfaction = a[i];
            if(last>=0) satisfaction += bonus[last][i];
            ans = max(ans, satisfaction + f(index+1, mask|1<<i, i, m, n, a, bonus, dp));
        }
    }
    return dp[mask][last+1] = ans;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m, k; cin>>n>>m>>k;
    vector<int> a(n);
    for(auto &i:a) cin>>i;
    vector<vector<int>> bonus(n, vector<int>(n, 0));

    while(k--){
        int a, b, c; cin>>a>>b>>c;
        bonus[a-1][b-1] = c; // we are using 0 base indexing
    }
    vector<vector<int>> dp(1<<n, vector<int>(n+1, -1));
    cout<<f(0, 0, -1, m, n, a, bonus, dp)<<endl;

    return 0;
}