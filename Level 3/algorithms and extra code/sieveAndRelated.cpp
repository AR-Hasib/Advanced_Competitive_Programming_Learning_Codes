#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;


// // sieve for finding prime numbers
// void sieve(vector<bool> &v, int n){      // send empty vector here
//     for(int i=0; i<=n; i++) v.push_back(true);
//     v[0]=false, v[1]=false;
//     for(int i=2; i*i<=n; i++){
//         if(v[i]){
//             for(long long j=(i*i)%MOD; j<=n; j+=i){
//                 v[j]=false;
//             }
//         }
//     }
// }


// // sieve to find the smallest prime factor of any number
// void sieveSPF(vector<int> &v, int n){
//     for(int i=0; i<=n; i++) v.push_back(i);
//     v[0]=-1, v[1]=-1;
//     for(int i=2; i*i<=n; i++){
//         if(v[i]==i){
//             for(long long j=(i*i)%MOD; j<=n; j+=i){
//                 if(v[j]==j) v[j]=i;
//             }
//         }
//     }
// }


// // printing all prime factors and their power using the previous sieveSPF function
// void printPrimeFactorsAndPower(vector<int> &v, int number){
//     while(number!=1){
//         int x=v[number]; int count=0;
//         while(number%x==0){
//             number/=x;
//             count++;
//         }
//         cout<<x<<"\t"<<count<<endl;
//     }
// }




int main(){
    int n=1e6;
    vector<int>v;
    // sieveSPF(v, n);
    // printPrimeFactorsAndPower(v, 19);
    
}