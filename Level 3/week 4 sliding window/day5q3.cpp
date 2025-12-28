/* https://cses.fi/problemset/task/1641 */

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
    int n, target; cin>>n>>target;
    vector<pair<int, int>>v;
    for(int i=0; i<n; i++){
        int temp; cin>>temp;
        v.push_back({temp, i+1}); // 1 base index
    }

    sort(v.begin(), v.end());

    bool flag= false;
    for(int a=0; a<n-2; a++){
        int i=a+1, j=n-1;
        int sum= target - v[a].first;
        if(sum<=0) continue;

        while(i<j){
            int x=v[i].first, y=v[j].first;
            if(x+y==sum){
                flag=true;
                break;
            }else if(x+y<sum){
                i++;
            }else{
                j--;
            }
        }
        if(flag){
            cout<<v[a].second<<" "<<v[i].second<<" "<<v[j].second;
            return;
        }
    }

    cout<<"IMPOSSIBLE";
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    solve();
    
    return 0;
}