/* https://atcoder.jp/contests/abc244/tasks/abc244_b

Problem Statement
Consider an xy-plane. The positive direction of the x-axis is in the direction of east, and the positive direction of the y-axis is in the direction of north.
Takahashi is initially at point (x, y) = (0,0) and facing east (in the positive direction of the x-axis).
You are given a string T = t₁t₂...ty of length N consisting of s and R. Takahashi will do the following move for each i=1,2,..., N in this order.
Ift; = s, Takahashi advances in the current direction by distance 1.
Ift; = R, Takahashi turns 90 degrees clockwise without changing his position. As a result, Takahashi's direction changes as follows.
• If he is facing east (in the positive direction of the x-axis) before he turns, he will face south (in the negative direction of the y-axis) after he turns.
• If he is facing south (in the negative direction of the y-axis) before he turns, he will face west (in the negative direction of the x-axis) after he turns.
• If he is facing west (in the negative direction of the x-axis) before he turns, he will face north (in the positive direction of the y-axis) after he turns.
• If he is facing north (in the positive direction of the y-axis) before he turns, he will face east (in the positive direction of the x-axis) after he turns.
Print the coordinates Takahashi is at after all the steps above have been done.
.
Constraints
• 1≤N ≤ 105
• N is an integer.
• T' is a string of length N consisting of s and R.
Input
Input is given from Standard Input in the following format:
N
T
Output
Print the coordinates (x, y) Takahashi is at after all the steps described in the Problem Statement have been completed, in the following format, with a space
in between:
x y
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
   int n;
   string s;
   cin>>n>>s;

   int x=0, y=0;
   char dir= 'E';

   for(int i=0; i<n; i++){
        if(s[i]=='S'){
            if(dir=='E') x++;
            else if(dir=='S') y--;
            else if(dir=='W') x--;
            else if(dir=='N') y++;
        }else if(s[i]=='R'){
            if(dir=='E') dir='S';
            else if(dir=='S') dir='W';
            else if(dir=='W') dir='N';
            else if(dir=='N') dir='E';
        }
   }
   cout<<x<<' '<<y;
   return 0;
}