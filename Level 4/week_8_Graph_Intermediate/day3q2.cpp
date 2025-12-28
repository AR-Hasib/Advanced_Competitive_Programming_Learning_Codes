/* https://codeforces.com/problemset/problem/1651/D */

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
#define setAll(x, y) memset(x, y, sizeof(x))
#define printVector(vctr) for(auto &vlu:vctr) cout<<vlu<<" "; cout<<endl;
#define VV(x) vector<vector<x>>

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<pair<int, int>> v;
    set<pair<int, int>> points; // to check a point is given or not
    map<pair<int, int>, pair<int, int>> ans;    // to store the answers
    for(int i=0; i<n; i++){
        int x, y; cin>>x>>y;
        v.push_back({x, y});
        points.insert({x, y});
    }

    queue<pair<int, int>> q;
    // i have to store those points whose mDistance is 1 then run multy bfs
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, 1, -1};
    for(int i=0; i<n; i++){
        int x = v[i].first, y = v[i].second;
        for(int k=0; k<4; k++){
            int nx = x+dx[k], ny = y+dy[k];

            // if the point is not given, it means it is a exit point at distance 1
            if(!points.count({nx, ny})){
                q.push({x, y});
                ans[{x, y}] = {nx, ny};
                break;
            }
        }
    }

    while(!q.empty()){
        auto temp = q.front(); q.pop();
        int x = temp.first, y = temp.second;

        for(int k=0; k<4; k++){
            int nx = x+dx[k], ny = y+dy[k];

            /* if there is some empty cell between two points, it means both of them 
            have mDist 1 (already on the queue). so now we have to calculate for
            contiguos cells only.
            a point is in v and its answer is not calculated meaning it is a 
            contiguos point from the current {x, y} */

            if(points.count({nx, ny}) && !ans.count({nx, ny})){
                ans[{nx, ny}] = ans[{x, y}];
                q.push({nx, ny});
            }
        }
    }

    for(auto i:v){
        auto temp = ans[i];
        cout<<temp.first<<" "<<temp.second<<endl;
    }

    return 0;
}