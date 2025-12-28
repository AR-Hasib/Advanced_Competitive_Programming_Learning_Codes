/* https://codeforces.com/problemset/problem/1251/C */

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

void solve(){
    string s; cin>>s;
    string even="", odd="";
    for(auto i:s){
        if((i-'0')%2) odd+=i;
        else even+=i;
    }

    string ans="";
    int i=0, j=0;
    while(i<even.length() && j<odd.length()){
        if((even[i]-'0')<(odd[j]-'0')){
            ans+=even[i];
            i++;
        }else{
            ans+=odd[j];
            j++;
        }
    }
    while(i<even.length()){
        ans+=even[i];
        i++;
    }
    while(j<odd.length()){
        ans+=odd[j];
        j++;
    }
    cout<<ans<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}