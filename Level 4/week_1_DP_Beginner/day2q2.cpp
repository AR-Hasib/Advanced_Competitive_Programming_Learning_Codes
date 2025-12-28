/* https://cses.fi/problemset/task/1639 */

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
    
    string a, b; cin>>a>>b;
    int n = a.length(), m = b.length();

    // without space optimization
    vector<vector<int>> dp(n+1, vector<int> (m+1, 1e6));
    /* dp[i][j]=min operation required to match 1st i char of a
    with the 1st j char of b */

    for(int i=0; i<=n; i++) dp[i][0]=i;
    for(int j=0; j<=m; j++) dp[0][j]=j;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char x = a[i-1], y = b[j-1];

            if(x==y){
                dp[i][j] = dp[i-1][j-1]; // same, no need to do anything
            }else{
                dp[i][j] = dp[i-1][j-1]+1; // replace charcter to match, +1 is to do the curr ope
            }

            // skip ith char or add 1 char after jth char to match
            dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
            // skip jth char or add 1 char after ith char to match
            dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
        }
    }
    cout<<dp[n][m]<<endl;

    return 0;
}