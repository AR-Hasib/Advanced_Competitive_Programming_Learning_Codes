/* https://atcoder.jp/contests/abc276/tasks/abc276_d

time 2s
Problem Statement
You are given a sequence of positive integers: A = (a1, a2, ..., an).
You can choose and perform one of the following operations any number of times, possibly zero.
• Choose an integer i such that 1 ≤ i ≤ N and a; is a multiple of 2, and replace a; with .
• Choose an integer i such that 1 ≤ i ≤ N and a; is a multiple of 3, and replace a with.
Your objective is to make A satisfy a₁ = a2 = ... = an.
Find the minimum total number of times you need to perform an operation to achieve the objective. If there is no way to achieve the objective, print -1
instead.

Constraints
• 2 ≤ N≤ 1000
• 1 ≤ ai ≤ 10⁹
• All values in the input are integers.

Input
The input is given from Standard Input in the following format:
N
a1 a2

Output
Print the answer.
aN
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
    int arr[n];
    int g=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        g=__gcd(g, arr[i]);
    }
    for(int i=0; i<n; i++) arr[i]/=g;

    int ans=0;
    for(int i=0; i<n; i++){
        while(arr[i]%2==0){
            arr[i]/=2;
            ans++;
        }
        while(arr[i]%3==0){
            arr[i]/=3;
            ans++;
        }
        if(arr[i]!=1){
            cout<<-1;
            return 0;
        }
    }
    cout<<ans;

    return 0;
}