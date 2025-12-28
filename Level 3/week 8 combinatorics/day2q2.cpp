/* https://codeforces.com/problemset/problem/476/B */

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

// needed for recursion
int match=0;
void check(int curr, int need, int digits){
    if(digits==0){
        if(need==curr) match++;
        return;
    }

    check(curr+1, need, digits-1);
    check(curr-1, need, digits-1);
}

// choose template
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

void solve(){
    string original, recieved; cin>>original>>recieved;
    int or_plus=0, or_minus=0, re_plus=0, re_minus=0, not_rec=0;

    for(auto i:original){
        if(i=='+') or_plus++;
        else or_minus++;
    }

    for(auto i:recieved){
        if(i=='+') re_plus++;
        else if(i=='-') re_minus++;
        else not_rec++;
    }

    // when all recognized and total is same. it is obvious
    if(or_plus==re_plus && or_minus==re_minus){ cout<<precision(12)<<1.0<<endl; return; }
    // when all recognized but total is different
    if(not_rec==0){ cout<<precision(12)<<0.0<<endl; return; }

    // when unrecognized can't fullfill one of type
    if(not_rec+re_plus < or_plus){ cout<<precision(12)<<0.0<<endl; return; }
    if(not_rec+re_minus < or_minus){ cout<<precision(12)<<0.0<<endl; return; }

    // when it is possible
    int plus_need = or_plus-re_plus, minus_need = or_minus-re_minus;
    
    // int needed = plus_need-minus_need;
    // check(0, needed, not_rec);   ld numerator = match;
    // i used recursion system here because in the worst case the recursion will do 2^10 = 1024 operation

    /* if the length of the string is so large then we can use combinatorics here.
        we have to choose plus_need from not_recognized digits. so we can just do choose(not_rec, plus_need) */
    Math<int>m(15);
    ld numerator = m.choose(not_rec, plus_need);

    ld denominator = pow(2, not_rec);

    cout<<precision(12)<<numerator/denominator<<endl;
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}