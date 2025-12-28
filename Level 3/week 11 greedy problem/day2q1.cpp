/* https://codeforces.com/problemset/problem/1810/C */

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

void solve(){
    ll n, rCost, addCost; cin>>n>>rCost>>addCost;
    vector<ll> v(n);
    for(auto &i:v) cin>>i;
    sort(v.begin(), v.end());

    vector<ll> vNew;
    for (ll i = 0; i < n; i++) {  // Include the last element
        if (i == 0 || v[i] != v[i - 1]) {
            vNew.push_back(v[i]);  // Removing duplicates
        }
    }

    ll m = vNew.size();
    ll extraCost = (n-m)*rCost;     // duplicate removing cost
    ll cost = LLONG_MAX;

    // assume i will make permutation of vNew[i] length
    ll totalAddingCost=0; 
    for(ll i=0; i<m; i++){
        ll req;
        if(i==0) req = vNew[i]-1;
        else req = vNew[i]-vNew[i-1]-1;

        ll currAddingCost = req*addCost;
        ll removingCost = (m-i-1)*rCost;
        totalAddingCost += currAddingCost;

        cost = min(cost, totalAddingCost+removingCost);
    }

    cost += extraCost;
    
    // removing all and just insert 1
    if((n*rCost)+addCost < cost) cost = (n*rCost)+addCost;

    cout<<cost<<endl;
    return;
}

int main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    ll tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}