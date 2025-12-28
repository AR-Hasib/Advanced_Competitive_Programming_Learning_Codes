/* https://codeforces.com/contest/1341/problem/B */

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
    int n, k; cin>>n>>k;
    vector<int>v(n);
    for(auto &i:v) cin>>i;

    vector<int>peak(n, 0);
    for(int i=1; i<n-1; i++) if(v[i]>v[i-1] && v[i]>v[i+1]) peak[i]=1;  // mark where there is a peak
    for(int i=1; i<n; i++) peak[i]+=peak[i-1];  // prefix sum of peak

    int ansPeak=0, left=0;  // door itself 1 part, if there is no mountain i have to still keep left to 1st index
    for(int i=0; i+k<=n; i++){
        int currPeak= peak[i+k-2]-peak[i];  // peak of the boundary has to ignore
        if(currPeak>ansPeak){               // has to keep leftmost so only <
            ansPeak=currPeak;
            left=i;
        }
    }
    cout<<ansPeak+1<<" "<<left+1<<endl;     // total split part = peak+1, 1 base index
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}