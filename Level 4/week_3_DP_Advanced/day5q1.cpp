/* https://cses.fi/problemset/task/2220 */

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
#define setAll(x, y) memset(x, y, sizeof(x))

const int MOD = 1e9 + 7;

int dp[20][2][11][2];

int f(int index, int tight, int last, bool allZeroTillNow, string &s, int n){
    if(index == n) return 1;
    if(dp[index][tight][last+1][allZeroTillNow] != -1) return dp[index][tight][last+1][allZeroTillNow];

    int range = tight ? s[index]-'0' : 9;
    int ans = 0;
    for(int i=0; i<=range; i++){
        if((i != last) || allZeroTillNow) ans = (ans + f(index+1, tight && (i == s[index]-'0'), i, allZeroTillNow && (i==0), s, n));
    }
    return dp[index][tight][last+1][allZeroTillNow] = ans;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int left, right; cin>>left>>right;
    left--;

    string l, r;
    if(left>=0) l = to_string(left);
    r = to_string(right);

    setAll(dp, -1);
    int rightTotal = right != 0 ? f(0, 1, -1, true, r, r.size()):1; // when right is 0, left is obviously 0. so i have to output 1
    
    setAll(dp, -1);
    int leftTotal = left != -1 ? f(0, 1, -1, true, l, l.size()):0;  // 0 is itself a number satisfying the requirement

    cout<<rightTotal-leftTotal<<endl;
    
    return 0;
}