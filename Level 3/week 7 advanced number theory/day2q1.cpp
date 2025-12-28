/* https://codeforces.com/problemset/problem/495/B */

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
    int a, b; cin>>a>>b;
    int ans=0;
    if(a==b) cout<<"infinity"<<endl;
    else if(a<b || b>a/2) cout<<0<<endl;    // remainder has to be less than or equal to half of quotient
    else{
        int temp= a-b;
        for(int i=1; i*i<=temp; i++){
            if(temp%i==0){
                if(i>b) ans++;
                if((i!=temp/i) && (temp/i > b)) ans++;
            }
        }

       cout<<ans<<endl; 
    }
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    solve();

    return 0;
}