/* https://codeforces.com/contest/816/problem/B */

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
    
    int n, k, querry; cin>>n>>k>>querry;
    vector<ll>temp(200000, 0); // keep a freq vector of the temperature
    while(n--){
        int a, b; cin>>a>>b;
        --a; --b;
        temp[a]++;
        if(b+1 < 200000) temp[b+1]--;
    }
    for(int i=1; i<200000; i++) temp[i]+=temp[i-1]; // this sum vector now store the frequency

    // now we want to store a vector which store the permissable temp freq from 0 to index i
    int sum=0;
    for(int i=0; i<200000; i++){
        if(temp[i]>=k) sum++;
        temp[i]=sum;
    }

    while(querry--){
        int l, r; cin>>l>>r;
        l--; r--;
        int ans=temp[r];
        if(l-1>=0) ans-=temp[l-1];
        cout<<ans<<endl;
    }

    return 0;
}