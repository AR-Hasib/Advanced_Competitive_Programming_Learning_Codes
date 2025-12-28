/* https://codeforces.com/contest/1420/problem/A

Wheatley decided to try to make a test chamber. He made a nice test chamber, but there was only one detail absent — cubes.
For completing the chamber Wheatley needs n cubes. i-th cube has a volume ai.
Wheatley has to place cubes in such a way that they would be sorted in a non-decreasing order by their volume. Formally, for each i > 1,
ai-1<a; must hold.
To achieve his goal, Wheatley can exchange two neighbouring cubes. It means that for any i > 1 you can exchange cubes on positions
i - 1 and i.
But there is a problem: Wheatley is very impatient. If Wheatley needs more than (n.(n-1)/2)-1 exchange operations, he won't do this boringwork.
Wheatly wants to know: can cubes be sorted under this conditions?

Input
Each test contains multiple test cases.

The first line contains one positive integer t (1 ≤ t ≤ 1000), denoting the number of test cases. Description the test cases follows.
The first line of each test case contains one positive integer n (2 ≤ n ≤ 5 · 104) — number of cubes.
The second line contains n positive integers ai (1 ≤ ai ≤ 10⁹)- volumes of cubes.
It is guaranteed that the sum of n over all test cases does not exceed 105.
Output
For each test case, print a word in a single line: "YES" (without quotation marks) if the cubes can be sorted and "NO" (without quotation
marks) otherwise.*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];

        bool flag= false;
        for(int i=0; i<n-1; i++){
            if(arr[i]<=arr[i+1]){
                flag=true;
                break;
            }
        } 
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
   return 0;
}