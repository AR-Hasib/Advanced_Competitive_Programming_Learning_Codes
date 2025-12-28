/* https://cses.fi/problemset/task/1081 */

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
const int max_val=1e6;

void solve(){
    int n; cin>>n;
    vector<int>m(max_val+1, 0);
    while(n--){
        int i; cin>>i;
        m[i]++;
    }

    for(int i=max_val; i>=1; i--){
        int count=0;
        for(int j=i; j<=max_val; j+=i){   // counting how many multiple of j present here
            count+=m[j];
        }
        if(count>1){
            cout<<i<<endl;
            return;
        }
    }
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    solve();
    return 0;
}