/* https://codeforces.com/problemset/problem/981/C */

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
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define precision fixed<<setprecision
#define toLDouble static_cast<long double>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define setAll(x, y) memset(x, y, sizeof(x))

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<int> degree(n+1, 0);
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        degree[a]++;
        degree[b]++;
    }

    int countOfOne = 0, countOfTwo = 0, countMore = 0;
    for(int i=1; i<=n; i++){
        if(degree[i] == 1) countOfOne++;
        else if(degree[i] == 2) countOfTwo++;
        else countMore++;
    }

    // 1st case when it is bamboo tree 0-0-0-0-0-0
    if((countOfTwo == n-2) && (countOfOne == 2)){
        yes;
        cout<<1<<endl;
        for(int i=1; i<=n; i++) 
            if(degree[i] == 1) cout<<i<<" ";
        cout<<endl;
    }else if(countMore == 1){
        yes;
        int node = -1;
        for(int i=1; i<=n; i++) 
            if(degree[i] > 2) node = i;
        cout<<degree[node]<<endl;
        for(int i=1; i<=n; i++) 
            if(degree[i] == 1) cout<<node<<" "<<i<<endl;
    }else{
        no;
    }

    return 0;
}