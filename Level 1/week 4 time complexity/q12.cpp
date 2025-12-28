/* https://codeforces.com/contest/1703/problem/E

You are given a square grid with n rows and n columns. Each cell contains either 0 or 1.

In an operation, you can select a cell of the grid and flip it (from 0→1 or 1→0).
Find the minimum number of operations you need to obtain a square that remains the same when rotated 0∘, 90∘, 180∘ and 270∘.

input
t test case 1<=t<=100
n 1<=n<=100
aij...

output
minimum number of operation
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        int n; cin>>n;
        int arr[n][n];
        for(int i=0; i<n; i++){
            string s; cin>>s;
            for(int j=0; j<n; j++){
                if(s[j]=='0') arr[i][j] = 0;
                else arr[i][j] = 1;
            }
        }

        int m= n-1, cost=0, cnt0=0, cnt1=0;
        for(int a=0; a<=((n/2)-1); a++){
            for(int b=a; b<m-a; b++){
                if(arr[a][b] == 0) cnt0++; else cnt1++;
                if(arr[b][m-a] == 0) cnt0++; else cnt1++;
                if(arr[m-b][a] == 0) cnt0++; else cnt1++;
                if(arr[m-a][m-b] == 0) cnt0++; else cnt1++;
                cost+=min(cnt0, cnt1);
                cnt0=0; cnt1=0;
            }
            
        }
        cout<<cost<<endl;
    }
    return 0;
}
