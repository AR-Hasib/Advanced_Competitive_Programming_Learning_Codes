/* https://codeforces.com/problemset/problem/576/A */

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

    vector<int> primes(n+1, 1);

    for(int i=2; i<=n; i++){
        if(primes[i]){
            for(int j=i*i; j<=n; j+=i) primes[j]=0;
        }
    }

    vector<int>ans;
    for(int i=2; i<=n; i++){
        if(primes[i]){
            for(int x=i; x<=n; x*=i) ans.push_back(x);
        }
    }

    cout<<ans.size()<<endl;
    for(auto i:ans) cout<<i<<" ";
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    solve();

    return 0;
}