/* https://codeforces.com/problemset/problem/1466/D */

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
#define toLDouble static_cast<long double>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define setAll(x, y) memset(x, y, sizeof(x))

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

void solve(){
    int n; cin>>n;
    vector<int> weight(n), degree(n);
    for(auto &i:weight) cin>>i;

    for(int i=1; i<n; i++){
        int a, b; cin>>a>>b;
        a--, b--; // 1 -> 0 base
        degree[a]++;
        degree[b]++;
    }

    int sum = 0;
    for(auto &i:weight) sum+=i;

    priority_queue<int> box;
    // i will add the extra edges(wight) of every node
    for(int i=0; i<n; i++){
        for(int j=1; j<degree[i]; j++) box.push(weight[i]);
    }

    cout<<sum<<" "; // k=1
    for(int k=2; k<n; k++){
        if(!(box.empty())){
            sum += box.top();
            box.pop();
        }
        cout<<sum<<" ";
    }
    cout<<endl;
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