/* https://cses.fi/problemset/task/1638 */

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

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    string arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    // // without space optimization
    // vector<vector<int>> dp(n, vector<int>(n));

    // dp[n-1][n-1] = arr[n-1][n-1]=='.' ? 1:0;

    // for(int i=n-1; i>=0; i--){
    //     for(int j=n-1; j>=0; j--){
    //         if(i==n-1 && j==n-1) continue;  // already calculated
    //         if(arr[i][j]=='*') dp[i][j]=0;   // bomb
    //         else{
    //             int ans1 = i<n-1 ? dp[i+1][j]:0;
    //             int ans2 = j<n-1 ? dp[i][j+1]:0;
    //             dp[i][j] = (ans1+ans2)%MOD;
    //         }
    //     }
    // }
    // cout<<dp[0][0]<<endl;

    // space optimized

    vector<int> dp(n, 0);

    if(arr[n-1][n-1]=='*') cout<<0<<endl;
    else{
        for(int x=n-1; x>=0; x--){
            if(arr[n-1][x]=='.') dp[x]=1;
            else break;
        }
        for(int r=n-2; r>=0; r--){
            for(int c=n-1; c>=0; c--){
                if(arr[r][c]=='*'){
                    dp[c]=0;
                }else{
                    if(c!=n-1) dp[c] = (dp[c]+dp[c+1])%MOD;
                }
            }
        }
        cout<<dp[0]; 
    }
    
    return 0;
}