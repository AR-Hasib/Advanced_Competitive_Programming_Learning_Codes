/* https://cses.fi/problemset/task/1632 */

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

struct movie{
    int start, end;
};

bool compare(const movie a, const movie b) {
    return a.end < b.end;
}

void solve(){
    int n, k; cin>>n>>k;
    vector<movie> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i].start;
        cin>>v[i].end;
    }
    sort(v.begin(), v.end(), compare);

    int count=0;
    multiset<int> s;
    for(int i=0; i<k; i++) s.insert(-1);

    for(auto i:v){
        auto it = s.upper_bound(i.start);

        if(it==s.begin()) continue;

        s.erase(--it);
        s.insert(i.end);
        count++;
    }
    cout<<count<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}