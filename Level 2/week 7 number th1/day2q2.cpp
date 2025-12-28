/* https://codeforces.com/contest/271/problem/B */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

vector<int>primes;
vector<bool>isPrime;

void sieve(ll n){
    isPrime.assign(n+1, true);
    isPrime[0]=isPrime[1]=false;

    for(ll i=2; i*i<=n; i++){
        if(isPrime[i]){
            for(ll j=i*i; j<=n; j+=i)
                isPrime[j]=false;
        }
    }
    for(ll i=2; i<=n; i++){
        if(isPrime[i]) primes.push_back(i);
    }
}

int main(){

    sieve(100100);
    
    int n,m; cin>>n>>m;
    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin>>arr[i][j];
    }

    int ans=INT_MAX;

    for(int i=0; i<n; i++){
        int row=0;
        for(int j=0; j<m; j++){
            int x=(*lower_bound(primes.begin(), primes.end(), arr[i][j]));
            row+= x-arr[i][j];
        }
        ans=min(ans, row);
    }

    for(int i=0; i<m; i++){
        int col=0;
        for(int j=0; j<n; j++){
            int y=(*lower_bound(primes.begin(), primes.end(), arr[j][i]));
            col+= y-arr[j][i];
        }
        ans=min(ans, col);
    }

    cout<<ans<<endl;

    return 0;
}