/* https://atcoder.jp/contests/abc131/tasks/abc131_d */

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
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define precision fixed<<setprecision

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

bool compare(pair<int, int> &a, pair<int, int> &b){
    return a.second<b.second;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), compare);

    int sum=0; bool flag=true;
    for(int i=0; i<n; i++){
        sum+=v[i].first;
        if(sum>v[i].second){
            flag = false;
            break;
        }
    }

    if(flag) yes;
    else no;

    return 0;
}