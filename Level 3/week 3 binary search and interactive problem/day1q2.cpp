/* https://codeforces.com/problemset/problem/1425/F */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

int query(int l, int r){
    cout<<"? "<<l<<" "<<r<<endl;
    int x; cin>>x;
    return x;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin>>n;
    vector<int>ans(n, 0);

    int total= query(1, n); // total sum
    int ex1=0;

    for(int i=n-1; i>=2; i--){
        int temp= query(1, i);
        ans[i]= total-temp-ex1; 
        ex1+=ans[i];
    }

    int temp= query(2, n);
    ans[0]=total-temp;
    ex1+=ans[0];
    ans[1]=total-ex1;

    cout<<"!";
    for(auto i:ans) cout<<" "<<i;
    cout<<endl;
    
    return 0;
}