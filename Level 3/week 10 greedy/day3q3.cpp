/* https://codeforces.com/problemset/problem/1675/E */

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

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

vector<char> numToChar={'1', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void solve(){
    int n, m; cin>>n>>m;
    string s, sNew=""; cin>>s;

    vector<int> v(n);
    for(int j=0; j<n; j++){
        v[j] = s[j]-'a'+1;
    }

    int i=0, mx=0;
    while(v[i]-1<=m && i<n){ 
        mx = max(mx, v[i]);
        v[i]=1;
        i++;
    }    // check from first that how much element i can make 'a'
    
    if(mx>0){
        for(int j=i; j<n; j++){
            if(v[j]<=mx) v[j]=1; // which are possible to make 'a'
        }
        m = m-mx+1; 
    }

    if(i<n && m>0){
        int temp = v[i]-m;
        for(int j=i+1; j<n; j++){
            if(v[j]>temp && v[j]<=v[i]) v[j]=temp;
        }
        v[i]=temp;
    }
    
    for(auto it:v) sNew.push_back(numToChar[it]);   
    cout<<sNew<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}