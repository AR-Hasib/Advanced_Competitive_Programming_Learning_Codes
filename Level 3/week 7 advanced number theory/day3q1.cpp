/* https://codeforces.com/problemset/problem/154/B */

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

void smallPrimeFactor(vector<int> &spf, int N){
    for(int i=1; i<N; i++) spf[i]=i;

    for(int i=2; i<N; i++){
        if(spf[i]==i){
            for(ll j=(i*i)%MOD; j<N; j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}

vector<int> primeFactors(int temp, vector<int> &spf){
    vector<int>primes;
    while(temp>1){
        int f= spf[temp];
        while(temp%f==0) temp/=f;
        primes.push_back(f);
    }
    return primes;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin>>n>>m;
    ++n;
    vector<int> occupied(n, 0), spf(n, 0);
    vector<bool> isOn(n, false);
    smallPrimeFactor(spf, n);

    while(m--){
        char type; int x; cin>>type>>x;
        vector<int>primes = primeFactors(x, spf);

        if(type=='+'){
            if(isOn[x]) cout<<"Already on"<<endl;
            else{
                bool conflict=false;
                for(auto f:primes){
                    if(occupied[f]){
                        conflict = true;
                        cout<<"Conflict with "<<occupied[f]<<endl;
                        break;
                    }
                }
                if(!conflict){
                    isOn[x]=true;
                    cout<<"Success"<<endl;
                    for(auto f:primes) occupied[f]=x;
                }
            }
        }else{
            if(!isOn[x]) cout<<"Already off"<<endl;
            else{
                isOn[x]=false;
                cout<<"Success"<<endl;
                for(auto f:primes) occupied[f]=0;
            }
        }
    }

    return 0;
}