/* https://codeforces.com/contest/1992/problem/F */

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
    int n, x; cin>>n>>x;
    vector<int> arr(n);
    for(auto &i: arr) cin>>i;   // taking input array

    set<int> current, factor;
    current.insert(1);

    for(int i=1; i*i<=x; i++){  // storing the factors of x
        if(x%i==0){
            factor.insert(i);
            factor.insert(x/i);
        }
    }

    int segment=1;
    for(int i=0; i<n; i++){
        set<int> newInsert;

        /* now i have to check is it possible to make any divisors of x with the multiplication of
        arr[i] and any element from current.and store those factors to newInsert.
        now if there is x in newInsert i have to exclude this arr[i] and make a segment before it.
        else i will add all the factor to my current set */

        for(auto j:factor){  
            if(j%arr[i]==0 && current.count(j/arr[i])){ // this count ensure there is the 2nd element present in current set (arr[i]*2nd element==factor)
                newInsert.insert(j);
            }
        }

        if(newInsert.count(x)){     // if x is present then we have to make a wall before arr[i]
            segment++;
            current.clear();        // clearing all i have
            current.insert(1);
            current.insert(arr[i]); // inserting current element i am in
        }else{                      // it is possible to take current element in this segment
            for(auto j:newInsert) current.insert(j);
        }
    }
    cout<<segment<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}