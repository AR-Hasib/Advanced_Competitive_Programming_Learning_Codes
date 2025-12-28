/* https://atcoder.jp/contests/abc103/tasks/abc103_c

time 2s
Problem Statement
You are given N positive integers a1, a2,..aN.
For a non-negative integer m, let f (m) = (m mod a1) + (m mod a2) + + (m mod aN).
Here, X mod Y denotes the remainder of the division of X by Y.
Find the maximum value of f.

Constraints
• All values in input are integers.
• 2 ≤ N≤ 3000
• 2 ≤ ai ≤ 10^5

Input
Input is given from Standard Input in the following format:
N
a1 a2....aN

Output
Print the maximum value of f.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, ans=0; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
       cin>>arr[i]; 
       ans+=arr[i]-1;
    } 
    cout<<ans;
    return 0;
}