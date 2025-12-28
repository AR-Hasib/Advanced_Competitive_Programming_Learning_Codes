/* https://codeforces.com/problemset/problem/1714/D*/

not solved

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

void solve(){
    string t;
        cin >> t;
        int n = sz(t);
        
        int m;
        cin >> m;
        vector<string> patterns(m);
        for(int i = 0; i < m; i++){
            cin >> patterns[i];
        }

        // dp[i][k] = minimum number of ops to colors all the colors from i to n - 1
        // in red such that the first k characters starting from i are already colored
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        // number of states = n * n
        // transition time per state => m * worst_case length of a pattern
        
        // Time Complexity:
            // O(|T| * |T| * |Number of Patters| * |Worst Case length of 1 patter|)
        
        // Space Complexity:
            // O(|T| * |T|)
        
        // dp[i][k] -> dp[i + 1][k - 1], dp[i + 1][max(k - 1, len(s_j)- 1)]
        // dp[i][anything] depends on dp[i + 1][something]
        
        for(int i = n - 1; i >= 0; i--){
            for(int k = 0; k < n; k++){
                
                // invalid state
                if(k > n - i){
                    dp[i][k] = 1e9;
                    continue;
                } 
                // already reached ans
                if(k == n - i){
                    dp[i][k] = 0;
                    continue;
                }
                // don't put any string
                // standing at i = n - 1
                // what can happen
                    // last character is colored -> dp[n - 1][1]
                    // last character is not colored -> dp[n - 1][0]
                
                int skip = 1e9;
                if(k != 0){
                    skip = dp[i + 1][k - 1];
                }
                
                // part 1
                int pick = 1e9;
                for(int j = 0; j < m; j++){
                    // we can only put the jth string on top of t starting from ith
                    // character if substring from ith character matches the jth string
                    // completely
                    int string_len = sz(patterns[j]);
                    
                    if(i + string_len <= n && t.substr(i, string_len) == patterns[j]){
                        int colorings = 1 + dp[i + 1][max(k - 1, string_len - 1)];
                        pick = min(pick, colorings);
                    }   
                }
                
                dp[i][k] = min(pick, skip);
            }    
        }
        // final subproblem
        cout << dp[0][0] << endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}