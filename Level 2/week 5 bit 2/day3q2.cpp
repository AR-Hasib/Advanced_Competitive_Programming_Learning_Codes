/* https://codeforces.com/problemset/problem/1601/A */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> res(33);
    for (int j = 0; j < 32; j++) {
        for (int i = 0; i < n; i++) {
            if (a[i] & (1 << j)) {
                res[j]++;
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        bool ok = true;
        for (int j = 0; j < 32; j++) {
            if (res[j] % i != 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans) {
        cout <<x<<" ";
    }
    cout<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}
