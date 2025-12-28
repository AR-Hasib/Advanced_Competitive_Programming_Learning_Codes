/* https://codeforces.com/problemset/problem/1349/A */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const int M = 1e9 + 7;

const int N = 200001;
int spf[N];

// Binary exponentiation
int power(int x, int y){  // x pow y
    int ans=1;
    while(y){
        if(y&1){        // checking whether the right most bit is 1 or not
            ans*=x; 
            ans%=M;   // 1e9 + 7
        }
        x*=x; x%=M;
        y>>=1;          // rightt shift (a>>b == a divided by (2 pow b) )
    }
    return ans;
}

// sieve to find the smallest prime factor of any number
void sieveSPF(){
    for(int i=0; i<N; i++) spf[i]=i;
    spf[0]=-1;
    for(int i=2; i*i<N; i++){
        if(spf[i]==i){
            for(long long j=i*i; j<N; j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}

void solve(){
    sieveSPF();

    int n; cin>>n;
    vector<int> v(n, 0);
    vector<vector<int>> prime(N);
    for(auto &i:v) cin>>i;

    for(auto i:v){
        while(i>1){
            int f = spf[i], count=0;
            while(i%f==0){
                i/=f;
                count++;
            }
            prime[f].push_back(count);  // storing the powers
        }
    }

    int lc=1;

    for(int i=1; i<N; i++){
        // sort(prime[i].begin(), prime[i].end());

        if(prime[i].size()<n-1){    // it means 2nd smallest power is (i the power 0 = 1)
            continue;
        }else if(prime[i].size()==n-1){     // 2nd smallest is the lowest power
            int x=1000000;
            for(auto j:prime[i]) x = min(x, j);
            lc*= power(i, x);
            // lc*= power(i, prime[i][0]);
        }else{      // size==n // 2nd smallest is actually 2nd smallest here
            int a=1000000, b=1000001;
            for(auto j:prime[i]){
                if(j>b) continue;
                else if(j<a){
                    b=a;
                    a=j;
                }else{  // a<j<b
                    b=j;
                }
            }
            lc*= power(i, b);
            // lc *= power(i, prime[i][1]);
        }
    }

    cout<<lc<<endl;
}

signed main(){
    
    solve();

    return 0;
}