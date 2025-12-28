/* https://codeforces.com/problemset/problem/1084/C */

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

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;
const int N = 1e5+2;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    string s; cin>>s;
    vector<char> v;
    for(auto i:s) if(i=='a' || i=='b') v.push_back(i);

    /* it can a sequence of many numbers. so we use combinatorics technique here.
    from every segment of a we can choose an a from there or not choose. finally we subtract 1
    for the case when we choosing no element from every segment. */

    int ans=1, i=0;
    int n=v.size();
    while(i<n){
        int currentSegment=0;
        while(v[i]=='a' && i<n){
            i++;
            currentSegment++;
        }
        ans = (ans * (currentSegment+1))%MOD;
        while(v[i]=='b' && i<n) i++;
    }
    
    cout<<ans-1<<endl;

    return 0;
}