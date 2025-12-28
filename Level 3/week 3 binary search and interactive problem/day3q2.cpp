/* https://codeforces.com/problemset/problem/1807/E */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

int query(int start, int end){
    cout<<"? "<<end-start+1;
    for(int i=start; i<=end; i++) cout<<" "<<i;
    cout<<endl;

    int x; cin>>x;
    return x;
}

void solve(){
    int n; cin>>n;
    n++;
    vector<int> stones(n, 0);
    for(int i=1; i<n; i++){
        cin>>stones[i];
        stones[i]+=stones[i-1];
    }

    int left=1, right=n-1;

    while(left<=right){
        int mid=(left+right)/2;

        int totalStones= stones[mid]-stones[left-1];
        int weight= query(left, mid);

        if(weight>totalStones) right= mid-1;
        else left= mid+1;
    }

    cout<<"! "<<left<<endl;

}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}