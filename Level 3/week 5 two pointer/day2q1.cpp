/* https://codeforces.com/problemset/problem/701/C */

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
    int n; cin>>n;
    string s; cin>>s;

    map<char, int>m;
    for(int i=0; i<n; i++) m[s[i]]++;
    int total= m.size();
    m.clear();

    int ans=INT_MAX;
    int i=0, j=0;
    while(j<n){
        m[s[j]]++;
        while(m.size()>=total){
            ans=min(ans, j-i+1);
            m[s[i]]--;
            if(m[s[i]]==0) m.erase(s[i]);
            i++;
        }
        j++;
    }
    cout<<ans<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
        solve();

    return 0;
}