#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;


// // Binary exponentiation
// long long binary_exponentiation(long long x, long long y, long long M){  // x pow y
//     long long ans=1;
//     while(y){
//         if(y&1){        // checking whether the right most bit is 1 or not
//             ans*=x; 
//             ans%=M;   // 1e9 + 7
//         }
//         x*=x; x%=M;
//         y>>=1;          // rightt shift (a>>b == a divided by (2 pow b) )
//     }
//     return ans%M;
// }


// // Euler Totient Function
// // finding number of co-prime of n
// int find_co_prime(int n){
//     int result=n;
//     for(int i=0; i*i<=n; i++){  // we can find this prime factors using sieve for better tc
//         if(n%i==0){
//             while(n%i==0) n/=i;
//             result -= result/i; // n*(1-1/p) == n-n/p
//         }
//     }
//     if(n>1) result -= result/n;
//     return result;
// }












int main(){

    // // calculation a pow b pow c
    // int a, b, c; cin>>a>>b>>c;
    // long long temp= binary_exponentiation(b, c, MOD-1);  // according to Fermat's Little Theorem
    // cout<<binary_exponentiation(a, temp, MOD);



}