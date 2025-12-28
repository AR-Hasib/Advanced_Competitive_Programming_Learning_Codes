/* https://codeforces.com/contest/26/problem/ */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;


signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    int ans=0;
    for(int i=0; i<=n; i++){
        int num=i;
        int cnt=0;
        for(int j=2; j*j<=num; j++){
            if(num%j==0){
                cnt++;
                while(num%j==0){
                    num/=j;
                }
            }
            if(cnt>2) break;
        }
        if(num>1) cnt++;
        if(cnt==2) ans++;
    }
    cout<<ans<<endl;
    return 0;
}