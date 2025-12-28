/* https://atcoder.jp/contests/dp/tasks/dp_s */

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

int const MOD = 1e9 + 7;

string num ; // max number
const int digit=10005, maxD=105; // assuming for declaring the vector
vector<vector<vector<int>>> dp(digit, vector<vector<int>>(2, vector<int>(maxD, -1)));
int d; // our target sum

int f(int index, int tight, int sum){
    if(index == sz(num)){
        if(sum == 0) return 1;
        return 0;
    }

    if(dp[index][tight][sum] != -1) return dp[index][tight][sum];

    int ans = 0;
    int bound = (tight == 1 ? num[index]-'0' : 9);
    for(int i=0; i<=bound; i++){
        ans= (ans + f(index+1, ((tight==1) && (i == num[index]-'0')) ? 1:0, (sum+i)%d))%MOD;
    }

    return dp[index][tight][sum] = ans;
}


signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin>>num>>d;
    int result = f(0, 1, 0) - 1;
    if(result<0) result += MOD;
    cout<<result<<endl;
    
    return 0;
}