/* https://atcoder.jp/contests/abc169/tasks/abc169_b

Problem Statement
Given N integers A1, ..., AN, compute A₁ *....* AN.
However, if the result exceeds 1018, print -1 instead.

Constraints
• 2<N< 10^5
• 0≤ Ai ≤ 10^18
All values in input are integers.
Input
Input is given from Standard Input in the following format:
N
A₁...AN
Output
Print the value A₁ *....* AN as an integer, or -1 if the value exceeds 10^18
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr[i]=x;
        if(x==0){
            cout<<0;
            return 0;
        }  
    } 

    int sum=1, mx= 1*pow(10, 18);
    for(int i=0; i<n; i++){
        if(sum>mx/arr[i]){
            cout<<-1;
            return 0;
        }
        sum*=arr[i];
    }
    cout<<sum;
    return 0;
}