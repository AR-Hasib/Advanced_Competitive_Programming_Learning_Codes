/* https://codeforces.com/problemset/problem/1095/C */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n, k; cin>>n>>k;

    if(k>n) no;
    else{
        vector<int>ans;
        for(int i=30; i>=0; i--){
            if(n&(1<<i)) ans.push_back(1<<i);
        }
        int size= ans.size();
        if(size>k) no;
        else{
            int i=0; 
            while(size<k){
                if(ans[i]==1) i++;
                else{
                    ans[i]/=2;
                    ans.push_back(ans[i]);
                    size++;
                } 
            }
            yes;
            for(auto i:ans) cout<<i<<" ";
            cout<<endl;
        }
    }    
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}