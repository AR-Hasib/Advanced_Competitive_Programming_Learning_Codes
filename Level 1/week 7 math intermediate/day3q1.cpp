/* https://www.spoj.com/problems/FACT0/

This is a problem to test the robustness of your Integer Factorization algorithm.
Given some integers, you need to factor them into product of prime numbers.
The largest integer given in the input file has 15 digits. FACT1 is a harder version of this problem (the numbers are larger).
You may need to use a general factorization algorithm since no special numbers (e.g. Fermat numbers) are considered when designing the input data.

Input
There are several numbers given, each one in a line.
The input ends with a number 0.
The number of test cases is about 10.

Output
For each number, print in a line the factorization of it. See examples below for the output format.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    while(n!=0){
        map<int, int>m;
        while(n%2==0){
            n/=2;
            m[2]++;
        }
        for(int i=3; i*i<n; i+=2){
            while(n%i==0){
                n/=i;
                m[i]++;
            }
        }
        if(n>2) m[n]++;

        for(auto it : m) cout<<it.first<<"^"<<it.second<<" ";
        cout<<endl;

        cin>>n;
        if(n==0) break;
    }
    return 0;
}