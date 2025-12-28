/* https://codeforces.com/problemset/problem/1714/G */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define int long long
#define ld long double
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define precision fixed<<setprecision
#define toLDouble static_cast<long double>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define setAll(x, y) memset(x, y, sizeof(x))

void DFS(int node, int &sumA, int &sumB, vector<vector<int>>& childrens, vector<int>& a, vector<int>& b, vector<int>& prefixB, vector<int>& ans){
    for(auto &child:childrens[node]){
        sumA += a[child];
        sumB += b[child];
        prefixB.push_back(sumB);

        int temp = upper_bound(prefixB.begin(), prefixB.end(), sumA)-prefixB.begin();
        ans[child] = temp;

        DFS(child, sumA, sumB, childrens, a, b, prefixB, ans);

        sumA -= a[child];
        sumB -= b[child];
        prefixB.pop_back();
    }
    return;
}

void solve(){
    int n; cin>>n;
    vector<vector<int>> childrens(n+1);
    vector<int>a(n+1, 0), b(n+1, 0);
    for(int i=2; i<=n; i++){
        int p, x, y; cin>>p>>x>>y;
        a[i] = x;
        b[i] = y;
        childrens[p].push_back(i); // storing only the childrens
    }

    vector<int> prefixB, ans(n+1);
    int sumA=0, sumB=0;
    DFS(1, sumA, sumB, childrens, a, b, prefixB, ans);

    for(int i=2; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}