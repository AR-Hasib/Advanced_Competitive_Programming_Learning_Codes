/* https://www.spoj.com/problems/AGGRCOW/ */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

bool possible(int position[], int n, int total_cow, int distance){
    int count=1, i=0, j=1;
    while(j<n){
        if(position[j]-position[i] >= distance){
            count++;
            i=j;
        }
        if(count>=total_cow) return true;
        j++;
    }
    return count>=total_cow;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);

    int tc; cin>>tc;
    while(tc--){
        int n, total_cow; cin>>n>>total_cow;
        int position[n];
        for(int i=0; i<n; i++) cin>>position[i];
        sort(position, position+n);

        int ans=-1, left=1, right=position[n-1]; 
        while(left<=right){
            int mid=(left+right)/2;
            if(possible(position, n, total_cow, mid)){
                ans=mid;
                left=mid+1;
            }else right=mid-1;
        }

        cout<<ans<<endl;
    }
    
    return 0;
}