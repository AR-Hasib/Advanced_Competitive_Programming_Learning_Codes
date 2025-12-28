/* https://codeforces.com/contest/2010/problem/C2 */

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
#define toLDouble static_cast<long double>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

#define int long long
struct Hash {
    const int MOD = 1e9 + 7, B1 = 5689, B2 = 8861;

    vector<pair<int, int>> hashes, power;
    // we are maintaining 1 base indexing
    Hash(string s) {
        hashes.assign(s.size() + 1, {0, 0});
        power.assign(s.size() + 1, {1, 1});

        for (int i = 0; i < s.size(); i++) { // creating prefix
            hashes[i + 1] = {
                (1ll * hashes[i].first * B1 + (s[i] - 'a' + 1)) % MOD,
                (1ll * hashes[i].second * B2 + (s[i] - 'a' + 1)) % MOD
            };
            power[i + 1] = {
                (1ll * power[i].first * B1) % MOD,
                (1ll * power[i].second * B2) % MOD
            };
        }
    }

    pair<int, int> sHash(int l, int r) {
        l++, r++; // as we stored in 1 based indexing but here input is in 0 based indexing
        int hash1 = (hashes[r].first - (1ll * hashes[l - 1].first * power[r - l + 1].first) % MOD + MOD) % MOD;
        int hash2 = (hashes[r].second - (1ll * hashes[l - 1].second * power[r - l + 1].second) % MOD + MOD) % MOD;
        return {hash1, hash2};
    }

    /* Use this in the main function:

    string s = "abcdefgh";
    Hash a(s);  // a is the object of storing hash of s
    int l = 1, r = 2;
    pair<int, int> hashValue = a.sHash(l, r); // hash of substring l to r (0 base indexing)

    */
};

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    string s; cin>>s;
    Hash a(s);

    int n = s.size();
    if(n<3){
        no; return 0;
    }

    int e1 = n-2, s2=1;
    while(e1>=s2){
        if(a.sHash(0, e1) == a.sHash(s2, n-1)){
            yes;
            cout<<s.substr(0, e1+1);
            return 0;
        }
        e1--; s2++;
    }
    no;

    return 0;
}