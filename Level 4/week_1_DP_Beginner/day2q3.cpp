/* https://codeforces.com/contest/414/problem/B */

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

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k; cin>>n>>k;

    vector<vector<int>> dp(k+1, vector<int> (n+1));
    // dp[index][last] represents the number of good sequences of length index that end with the number last.
    for(int i=0; i<=n; i++){
        dp[k][i]=1;
    }

    for(int index=k-1; index>=0; index--){
        for(int last=1; last<=n; last++){
            for(int current=last; current<=n; current+=last){
                dp[index][last] = (dp[index][last] + dp[index+1][current])%MOD;
            }
        }
    }
    cout<<dp[0][1]<<endl;



    // vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));

    // // Base case: sequences of length 1
    // for (int i = 1; i <= n; i++) {
    //     dp[i][1] = 1;
    // }

    // // Fill the dp table
    // for (int j = 2; j <= k; j++) {  // For lengths 2 to k
    //     for (int i = 1; i <= n; i++) {  // For each number i
    //         // For each divisor of i
    //         for (int d = i; d <= n; d += i) {
    //             dp[d][j] = (dp[d][j] + dp[i][j-1]) % MOD;
    //         }
    //     }
    // }

    // // Calculate the answer
    // long long result = 0;
    // for (int i = 1; i <= n; i++) {
    //     result = (result + dp[i][k]) % MOD;
    // }

    // cout << result << endl;


    return 0;
}