/* https://codeforces.com/contest/222/problem/c */

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

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;
const int N = 1e7+1;

int spf[N];

void sieve(){   // storing small prime factor
    for(int i=1; i<N; i++) spf[i]=i;

    for(int i=2; i<N; i++){
        if(spf[i]==i){
            for(int j=i*i; j<N; j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}

void solve(){
    sieve();
    int n, m; cin>>n>>m;
    map<int, int> p1, p2, p3;
    vector<int> a, b;

    for(int i=0; i<n; i++){     // numerator
        int x; cin>>x;
        a.push_back(x);
        
        while(x>1){
            int f= spf[x], count=0;
            while(x%f==0){
                count++;
                x/=f;
            }
            p1[f]+=count;       // storing prime factors and their powers
        }
    }

    for(int i=0; i<m; i++){     // denominator
        int x; cin>>x;
        b.push_back(x);
        
        while(x>1){
            int f= spf[x], count=0;
            while(x%f==0){
                count++;
                x/=f;
            }
            p2[f]+=count;
        }
    }

    for(auto i:p1){     // storing gcd in p3
        p3[i.first] = min(i.second, p2[i.first]);
    }

    p1=p2=p3;

    for(int i=0; i<n; i++){
        int x=a[i];
        while(x>1){
            int f=spf[x], count=0;
            while(x%f==0){
                count++; x/=f;
            }
            count = min(count, p1[f]);  // calculating how much i can remove
            p1[f]-=count;               // 
            while(count--) a[i]/=f;     // removing the gcd
        }
    }

    for(int i=0; i<m; i++){
        int x=b[i];
        while(x>1){
            int f=spf[x], count=0;
            while(x%f==0){
                count++; x/=f;
            }
            count = min(count, p2[f]);  // calculating how much i can remove
            p2[f]-=count;               // 
            while(count--) b[i]/=f;     // removing the gcd
        }
    }

    cout<<n<<" "<<m<<endl;
    for(auto i:a) cout<<i<<" ";
    cout<<endl;
    for(auto i:b) cout<<i<<" ";
    cout<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    solve();

    return 0;
}