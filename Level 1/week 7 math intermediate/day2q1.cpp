/* https://atcoder.jp/contests/abc131/tasks/abc131_c

Problem Statement
You are given four integers A, B, C, and D. Find the number of integers between A and B (inclusive) that can be evenly divided by neither Cnor D.

Constraints
• 1 ≤ A ≤ B < 10^18
• 1 ≤ C, D ≤ 10⁹
• All values in input are integers.

Input
Input is given from Standard Input in the following format:
A B C D

Output
Print the number of integers between A and B (inclusive) that can be evenly divided by neither C nor D.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

int mul(int a, int b, int val){
    int start=a/val, end=b/val;
    int ans=end-start;
    if(a%val==0) return ans+1; 
    return ans;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int a, b, c, d; cin>>a>>b>>c>>d;

    int total=b-a+1, x= (c*d)/__gcd(c,d),
    divC=mul(a, b, c), 
    divD=mul(a, b, d),
    divCD=mul(a, b, x);

    cout<<(total-(divC+divD-divCD));
    return 0;
}