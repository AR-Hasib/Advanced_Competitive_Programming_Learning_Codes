/*https://codeforces.com/problemset/problem/1742/F*/

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ll long long
#define ld long double
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define precision fixed<<setprecision

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int q; cin>>q;

    /* we have two string S and T. if we find a character (not a) for string T, then int the followings
    no matter what we are getting the answer will be always yes because we can place that (not a) char 
    at the first position of T and then S will be always smaller. in the same way if we don't find any 
    (not a) for T but find for S then untill we are not finding (not a) for T, the ans will be no because
    no matter where will place that (not a) char in S it will be always greater than T*/
    bool found_notA_S=false, found_notA_T=false;
    ll count_a_S=1, count_a_T=1; // count of a
    while(q--){
        int type, k;
        string x; cin>>type>>k>>x;
        
        if(!found_notA_T){  // if i found a (not a) for T, no need to check furthure
            for(auto i:x){
                if(type==1){
                    if(i=='a') count_a_S += k;
                    else found_notA_S = true;
                }else{
                    if(i=='a') count_a_T += k;
                    else found_notA_T = true;
                }
            }
        }

        if(found_notA_T) yes;
        else if(found_notA_S) no;
        else if(count_a_S < count_a_T) yes;
        else no;
    }
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}