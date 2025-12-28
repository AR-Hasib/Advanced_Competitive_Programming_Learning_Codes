/* https://www.spoj.com/problems/HS08PAUL/ */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

// sieve for finding prime numbers
void sieve(vector<bool> &v, int n){      // send empty vector here
    for(int i=0; i<=n; i++) v.push_back(true);
    v[0]=false, v[1]=false;

    for(int i=2; i*i<=n; i++){
        if(v[i]){
            for(long long j=(i*i)%MOD; j<=n; j+=i){
                v[j]=false;
            }
        }
    }
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<bool>v;
    int N=1e7+1;
    sieve(v, N);

    vector<int>prefix(N, 0);

    for(int i=1; i*i<N; i++){
        for(int j=1; (i*i)+(j*j*j*j)<N; j++){
            int temp = (i*i)+(j*j*j*j);
            if(v[temp]) prefix[temp]=1;
        }
    }

    for(int i=2; i<N; i++) prefix[i]+=prefix[i-1];

    int n; cin>>n;
    while(n--){
        int num; cin>>num;
        cout<<prefix[num]<<endl;
    }
    
    return 0;
}