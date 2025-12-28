/* https://codeforces.com/problemset/problem/1833/F */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

// Function to perform modular exponentiation
// It returns (base^exp) % MOD
ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

// Function to divide a by b under modulo MOD
ll mod_divide(ll a, ll b, ll mod) {
    // Compute the modular inverse of b mod MOD
    ll b_inv = mod_exp(b, mod - 2, mod);
    return (a * b_inv) % mod;
}

void solve(){
    int n, m; 
    cin >> n >> m;
    
    set<int> s;
    map<int, int> mp;
    
    // Reading the input and storing in a set and map
    while (n--) {
        int x; 
        cin >> x;
        mp[x]++;
        s.insert(x);
    }

    vector<int> dancers(s.begin(), s.end());  // Sorting unique elements
    int p = 0;
    ll ans = 0, curr = 1;
    
    for (int i = 0; i < dancers.size(); i++) {
        while (p < dancers.size() && dancers[p] - dancers[i] < m) {
            curr = (curr * mp[dancers[p]]) % MOD;
            p++;
        }
        
        // If we have exactly m dancers
        if (p - i == m) {
            ans = (ans + curr) % MOD;
        }
        
        // Remove the contribution of dancers[i] from curr
        curr = mod_divide(curr, mp[dancers[i]], MOD);
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc; 
    cin >> tc;
    
    while (tc--) {
        solve();
    }
    
    return 0;
}
