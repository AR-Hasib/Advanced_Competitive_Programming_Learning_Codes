/* https://codeforces.com/contest/940/problem/E */

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

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, c; cin>>n>>c;
    vector<int> a(n);
    for(auto &i:a) cin>>i;
    int sum = 0;
    for(auto i:a) sum+=i;

    if(c==1) cout<<0<<endl;
    else if(c>n) cout<<sum;
    else{
        vector<int> mn(n, 1e9); // it will store the minimum element from i-c+1 to i for every i
        multiset<int> box;
        for(int i=0; i<c; i++) box.insert(a[i]);
        mn[c-1] = *box.begin(); 
        for(int i=c; i<n; i++){
            box.erase(box.find(a[i-c]));
            box.insert(a[i]);
            mn[i] = *box.begin();
        }

        vector<int> dp(n, 0);
        // dp[i] = maximum sum of element can be remove till index i
        for(int i=1; i<n; i++){
            dp[i] = dp[i-1]; // the case when we are considering 1 length subsegment
            if(i >= c-1){
                int currMin = mn[i];
                int prefix = i-c >= 0? dp[i-c]:0;
                dp[i] = max(dp[i], prefix + currMin);
            }
        }
        cout<<sum-dp[n-1]<<endl;
    }

    return 0;
}