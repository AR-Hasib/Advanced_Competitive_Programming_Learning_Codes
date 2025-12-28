/* https://codeforces.com/problemset/problem/869/C */
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

#define int long long
const int MOD = 998244353;
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

int solve(int x, int y){
    Math<int>m(max(x, y) + 1);
    int result=0;

    for(int i=0; i<=min(x, y); i++){
        result = (result + ( (m.choose(x, i)*m.choose(y, i))%MOD *m.fact[i])%MOD )%MOD;
    }
    return result;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int a, b, c; cin>>a>>b>>c;
    int ans = (((solve(a, b)*solve(b, c))%MOD)*solve(c, a))%MOD;
    cout<<ans<<endl;

    return 0;
}