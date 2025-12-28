/* https://cses.fi/problemset/task/1633 */

/* in dp problem, at first i should find out how to break my big problem into the smaller subproblems 
then i have to solve the smallest subproblem and have to figure out how can i make a trasition to produce
the answer of the bigger problem from the smallest one */

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
    vector<int> dp(n+1, 0);
    dp[0]=1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=6; j++){
            // here assume j is the first throw's outcome from the dice
            if(j<=i){   // it means there is still some values after first throw which i need to calculate, and which is my subproblem
                dp[i] = (dp[i] + dp[i-j])%MOD; // transition // dp[i-j] is the subproblem which is already solved in previous iteration
            }
        }
    }
    cout<<dp[n];

    return 0;
}