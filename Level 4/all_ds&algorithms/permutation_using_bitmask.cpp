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
#define toLDouble static_cast<long double>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void f(int idx, int mask, vector<int> &v, int n){
    if(idx == n){
        for(auto i:v) cout<<i<<" ";
        cout<<endl;
    } 
    
    for(int i=0; i<n; i++){
        if(((1<<i)& mask)==0){
            // ith number has not been taken
            v.push_back(i+1); // 0 base indexing
            f(idx+1, mask | (1<<i), v, n);
            v.pop_back();
        }
    }
    return;
}

void permutation_bitmask(int n){
    vector<int> v;
    f(0, 0,v, n);
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int x; cin>>x;
    permutation_bitmask(x);

    return 0;
}