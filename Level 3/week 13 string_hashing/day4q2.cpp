/* https://codeforces.com/problemset/problem/126/B */

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
};

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    string s; cin>>s;
    int n = s.length();
    Hash a(s);

    vector<int> nomi;

    // collecting the lengths which have the same prefix and suffix 
    for(int i=0, j=n-1; i<n-1 && j>0; i++, j--){
        if(a.sHash(0, i) == a.sHash(j, n-1)) nomi.push_back(i+1);
    } 

    string ans="Just a legend";
    int curr=0;
    if(nomi.size()){
        int left=0, right=nomi.size()-1;
        while(left<=right){
            int midIndx = (left+right)/2;
            int mid = nomi[midIndx];
            pair<int, int> want = a.sHash(0, mid-1);
            bool flag = false;
            for(int i=1;  i+mid<n; i++){
                if(a.sHash(i, i+mid-1) == want){
                    flag = true;
                    break;
                }
            }

            if(flag){
                curr = mid;
                left = midIndx+1;
            }else{
                right = midIndx-1;
            }
        }
    }

    if(curr==0) cout<<ans<<endl;
    else{
        cout<<s.substr(0, curr)<<endl;
    }

    return 0;
}