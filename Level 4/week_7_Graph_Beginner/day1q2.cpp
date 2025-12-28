/* https://cses.fi/problemset/task/1193 */

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
    
    int n, m; cin>>n>>m;
    VV(char) v(n, vector<char>(m));
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0; j<m; j++){
            v[i][j] = s[j];
        }
    }

    int sX, sY, eX, eY;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j] == 'A') sX = i, sY = j;  // start index
            else if(v[i][j] == 'B') eX = i, eY = j; // end index
        }
    }

    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, 1, -1};
    vector<char> move = {'U', 'D', 'R', 'L'};
    VV(bool) visited(n, vector<bool>(m, false));
    VV(int) lastMove(n, vector<int>(m));

    queue<pair<int, int>> q;
    q.push({sX, sY});
    visited[sX][sY] = true;

    while(!q.empty()){
        pair<int, int> node = q.front(); q.pop();

        for(int i=0; i<4; i++){
            int nextX = node.first + dx[i], nextY = node.second + dy[i];

            if(nextX>=0 && nextX<n && nextY>=0 && nextY<m && visited[nextX][nextY]==false && v[nextX][nextY]!='#'){
                q.push({nextX, nextY});
                visited[nextX][nextY] = true;
                lastMove[nextX][nextY] = i;
            }
        }
    }

    if(visited[eX][eY]){
        yes;
        string ans = "";
        while(eX!=sX || eY!=sY){
            int p = lastMove[eX][eY];
            ans.push_back(move[p]);

            eX -= dx[p];
            eY -= dy[p];
        }

        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }else{
        no;
    }

    return 0;
}