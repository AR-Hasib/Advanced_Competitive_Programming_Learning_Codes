/* https://codeforces.com/contest/831/problem/D */

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
    
    int n, m, office; cin>>n>>m>>office;
    vector<int> positions(n), keys(m);
    for(auto &i:positions) cin>>i;
    for(auto &i:keys) cin>>i;

    /* the crutial part of the problem is that the ans will be the maximum time taken for 
    someone among all the people. because within that time everyone will be in the office */
    sort(all(positions)); sort(all(keys));
    vector<vector<int>> dp(n+1, vector<int> (m+1,INF));
    /* dp[i][j] = min time need for (i....n-1) people to go to office such that the keys 
    before jth are unusable */
    for(int i=0; i<=m; i++) dp[n][i] = 0; 

    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            int choice1 = max(abs(positions[i]-keys[j])+abs(keys[j]-office), dp[i+1][j+1]);
            int choice2 = dp[i][j+1];
            dp[i][j] = min(choice1, choice2);
        }
    }
    cout<<dp[0][0];

    return 0;
}