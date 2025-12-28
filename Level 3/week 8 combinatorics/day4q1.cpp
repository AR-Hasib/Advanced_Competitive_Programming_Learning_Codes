/* https://codeforces.com/problemset/problem/1475/E */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ld long double
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define precision fixed<<setprecision
#define int long long
const int MOD = 1e9 + 7;
const int N = 1e6;

int mod(int a, int m = MOD) {
return a % m;
}
template <class T> class Math {     // in this template must define int as long long
    public:
        vector<T> fact, invfact;
        Math() {}
        Math(int n) {
            fact.resize(n);
            invfact.resize(n);
            fact[0] = invfact[0] = 1;
            for (int i = 1; i < n; i++) {
                fact[i] = mod(i * fact[i - 1]);
                invfact[i] = modinv(fact[i]);
            }
        }
        T modinv(T x, T m = MOD) { return expo(x, m - 2, m); }
        T expo(T base, T exp, T m = MOD) {
            T res = 1;
            while (exp) {
                if (exp & 1)
                    res = mod(res * base, m);
                base = mod(base * base, m);
                exp >>= 1;
            }
            return res;
        }
        T choose(T n, T k) {
            if (k < 0 || k > n)
                return 0;
            T ans = fact[n];
            ans = mod(ans * invfact[n - k]);
            ans = mod(ans * invfact[k]);
            return ans;
        }
};

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    Math<int>m(1002);
    int tc; cin>>tc;
    while(tc--){
        int n, k; cin>>n>>k;
        vector<int>v(n);
        for(auto &i:v) cin>>i;

        sort(v.rbegin(), v.rend());

        int i=k-1, j=k-1;
        while(v[i-1]==v[k-1] && i>0) i--;
        while(v[j+1]==v[k-1] && j<n-1) j++;
        int last_digit = j-i+1;  // how much same element is available that is same as last element 
        int last_take = k-i;  // how much has to be taken from them
    
        int ans = m.choose(last_digit, last_take)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}