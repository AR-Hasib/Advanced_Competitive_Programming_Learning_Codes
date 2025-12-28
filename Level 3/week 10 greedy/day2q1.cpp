/* https://cses.fi/problemset/task/1164 */

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

struct person{
    int arrival, departure, index;
};

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<person>v(n);
    vector<int>ans(n);
    set<pair<int, int>>rooms;

    for(int i=0; i<n; i++){
        cin>>v[i].arrival>>v[i].departure;
        v[i].index=i;
    }

    sort(v.begin(), v.end(), [&](auto a, auto b){
        return a.arrival < b.arrival;
    });

    int totalRoom=0;
    for(auto person:v){
        int roomNumber;

        if(rooms.empty() || (*rooms.begin()).first > person.arrival){
            roomNumber = ++totalRoom;
        }else{
            roomNumber = (*rooms.begin()).second;
            rooms.erase(rooms.begin());
        }

        rooms.insert({person.departure+1, roomNumber});
        ans[person.index]=roomNumber;
    }

    cout<<totalRoom<<endl;
    for(auto i:ans) cout<<i<<" ";
    
    return 0;
}