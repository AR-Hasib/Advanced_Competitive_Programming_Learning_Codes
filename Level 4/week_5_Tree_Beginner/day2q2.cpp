/* https://codeforces.com/problemset/problem/930/A */

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

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<vector<int>> edges(n+1); // we will solve this problem in 1 base indexing
    for(int i=1; i<n; i++){
        int x; cin>>x;
        edges[x].push_back(i+1);
        edges[i+1].push_back(x);
    }

    vector<bool> visited(n+1, false);
    queue<int> q;
    visited[1] = true;
    q.push(1);
    int collected = 0;

    while(!q.empty()){
        int k = q.size();
        collected += (k%2);
        while(k--){    
            int curr = q.front();
            q.pop();

            for(auto &i:edges[curr]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    cout<<collected<<endl;
    
    return 0;
}