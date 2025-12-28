/* https://codeforces.com/problemset/problem/1486/C1 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

int query(int l, int r){
    if(l>=r) return -1;

    cout<<"? "<<l<<" "<<r<<endl;
    int x; cin>>x;
    return x;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    

    int n; cin>>n;
    int left=1, right=n;

    while(left<right){
        int mid=(left+right)/2;
        int idx2nd= query(left, right); // got the index of second large elements
        if(idx2nd<=mid){
            int idx= query(left, mid); // if the second idx is same, the largest is in this bound
            if(idx==idx2nd){
                right=mid;
            } else left=mid+1;
        }else{
            int idx= query(mid+1, right);
            if(idx==idx2nd){
                left= mid+1;
            } else right=mid;
        }   
    }

    cout<<"! "<<left<<endl;

    return 0;
}