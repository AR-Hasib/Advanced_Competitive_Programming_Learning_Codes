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

#define int long long
struct Hash{
    const int MOD = 1e9 + 7, B1 = 5689, B2 = 8861;

    vector<pair<int, int>>hashes, power;
    // we are maintaining 1 base indexing
    Hash(string s){
        hashes.assign(s.size()+1, {0, 0});
        power.assign(s.size()+1, {1, 1});

        for(int i=0; i<s.size(); i++){      // creating prefix
            hashes[i+1] = { (1ll * hashes[i].first * B1 +(s[i] - 'a'+1))%MOD,
                            (1ll * hashes[i].second * B2 +(s[i] - 'a'+1))%MOD};
            power[i+1]  = { (1ll * power[i].first * B1)%MOD,
                            (1ll * power[i].second * B2)%MOD};
        }
    }

    pair<int, int>sHash(int l, int r){
        l++, r++;   // as we stored in 1 based indexing but here input is in 0 based indexing
        int hash1 = (hashes[r].first - (1ll * hashes[l-1].first * power[r-l+1].first)%MOD + MOD)%MOD;
        int hash1 = (hashes[r].second - (1ll * hashes[l-1].second * power[r-l+1].second)%MOD + MOD)%MOD;
    }

    /* use this in main function
    
    string s="abcdefgh";
    Hash a(s);  // a is the object of storing hash of s
    int l=1, r=2;   
    pair<int, int> hashValue = a.sHash(l, r);// hash of substring l to r (0 base indexing)
    */
};

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    string s="abcdefgh";
    Hash a(s);
    int l=1, r=2;   
    pair<int, int> hashValue = a.sHash(l, r);// hash of substring l to r (0 base indexing)
    
    return 0;
}
