/*  https://atcoder.jp/contests/arc157/tasks/arc157_a

time: 2s
Problem Statement:
Determine whether there is a string S of length N consisting of X and Y that satisfies the following condition.

Condition: Among the (N−1) pairs of consecutive characters in S,
exactly A are XX,
exactly B are XY,
exactly C are YX, and
exactly D are YY.

Constraints
1≤N≤2×10^5 
A≥0
B≥0
C≥0
D≥0
A+B+C+D=N−1

Input
The input is given from Standard Input in the following format:
N A B C D

Output
If there is a string 
S that satisfies the condition, print Yes; otherwise, print No. */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, A, B, C, D;
    cin>>n>>A>>B>>C>>D;

    if(abs(B-C)<=1){
        if(A!=0 && D!=0){
            if(B>0 || C>0) cout<<"Yes";
            else cout<<"No";
        }else cout<<"Yes";
    }else cout<<"No";

   return 0;
}