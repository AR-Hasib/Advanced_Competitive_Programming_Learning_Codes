/* https://codeforces.com/problemset/problem/17/A

Nick is interested in prime numbers. Once he read about Goldbach problem. It states that every even integer greater than 2 
can be expressed as the sum of two primes. That got Nick's attention and he decided to invent a problem of his own and call 
it Noldbach problem. Since Nick is interested only in prime numbers, Noldbach problem states that at least k prime numbers 
from 2 to n inclusively can be expressed as the sum of three integer numbers: two neighboring prime numbers and 1. 
For example, 19 = 7 + 11 + 1, or 13 = 5 + 7 + 1.

Two prime numbers are called neighboring if there are no other prime numbers between them.

You are to help Nick, and find out if he is right or wrong.

Input
The first line of the input contains two integers n (2 ≤ n ≤ 1000) and k (0 ≤ k ≤ 1000).

Output
Output YES if at least k prime numbers from 2 to n inclusively can be expressed as it was described above. Otherwise output NO.*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k; cin >> n>>k;
    int arr[n];
    int count=0;
    for(int i=2; i<=n; i++){
        bool flag=false;
        for(int j=2; j<=sqrt(i); j++){
            if(i%j == 0){
               flag= true;
               break;
            }
        }
        if(flag== false){
            arr[count]= i;
            count++;
        }
    }
   
   if(count<k) cout<<"NO";
   else{
        int pcount=0;
        for(int i=0; i<count; i++){
            int sum= arr[i]+arr[i+1]+1;
            for(int j=0; j<=count; j++){
                if(sum == arr[j]){
                    pcount++;
                    break;
                }
            }
        }
        if(pcount>=k) cout<<"YES";
        else cout<<"NO";
   }
   
    return 0;
}