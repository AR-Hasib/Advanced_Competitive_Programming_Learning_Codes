/* https://www.spoj.com/problems/CCHESS/ */

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
const int INF = INT_MAX;

void solve(int a){
    int b, c, d; cin>>b>>c>>d;
    
    vector<int> dx = {-2, -2, -1, -1, 1, 1, 2, 2};
    vector<int> dy = {-1, 1, -2, 2, -2, 2, 1, -1};
    
    vector<vector<int>> dist(8, vector<int>(8, INF));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {a, b}});   // distance, node
    dist[a][b] = 0;
    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();
        int currDist = temp.first;
        int x = temp.second.first;
        int y = temp.second.second;
        
        if(dist[x][y] < currDist) continue;   // already have shorter distance

        for(int i=0; i<8; i++){
            int newX = x+dx[i];
            int newY = y+dy[i];
            if(newX>=0 && newY>=0 && newX<8 && newY<8){
                int newDist = ((newX*x)+(newY*y))+currDist;
        
                if(newDist < dist[newX][newY]){
                    dist[newX][newY] = newDist;
                    pq.push({newDist, {newX, newY}});
                }
            }
        }
    }

    if(dist[c][d] < INF) cout<<dist[c][d]<<endl;
    else cout<<-1<<endl;

    return;
}


signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int a;
    while(cin>>a){
        solve(a);
    }
    return 0;
}