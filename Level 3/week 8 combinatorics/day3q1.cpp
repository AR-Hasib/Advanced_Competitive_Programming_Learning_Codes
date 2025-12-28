/* https://codeforces.com/problemset/problem/584/B */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ld long double
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define precision fixed<<setprecision

const int INF = LLONG_MAX /2;
const int MOD = 1e9 + 7;

// Binary exponentiation
long long binary_exponentiation(long long x, long long y, long long M){  // x pow y
    long long ans=1;
    while(y){
        if(y&1){        // checking whether the right most bit is 1 or not
            ans*=x; 
            ans%=M;   // 1e9 + 7
        }
        x*=x; x%=M;
        y>>=1;          // rightt shift (a>>b == a divided by (2 pow b) )
    }
    return ans%M;
}

void solve(){
    int n; cin>>n;
    int total= binary_exponentiation(27, n, MOD);
    int invalid= binary_exponentiation(7, n, MOD);
    cout<< (total-invalid+MOD)%MOD <<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}