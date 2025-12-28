/* https://codeforces.com/problemset/problem/1277/B 

There are n positive integers a₁, a2, ..., an. For the one move you can choose any even value c and divide by two all elements that equal c.
For example, if a = [6, 8, 12, 6, 3, 12] and you choose c = 6, and a is transformed into a = [3, 8, 12, 3, 3, 12] after the move.
You need to find the minimal number of moves for transforming a to an array of only odd integers (each element shouldn't be divisible by 2).

Input
The first line of the input contains one integer t (1 ≤ t ≤ 104) — the number of test cases in the input. Then t test cases follow.
The first line of a test case contains n (1≤ n ≤ 2 · 105) — the number of integers in the sequence a. The second line contains positive
integers a₁, a2,... an (1 ≤ ai ≤ 10⁹).
The sum of n for all test cases in the input doesn't exceed 2. 105.

Output
For t test cases print the answers in the order of test cases in the input. The answer for the test case is the minimal number of moves
needed to make all numbers in the test case odd (i.e. not divisible by 2).
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve(int arr[], int n){
    set<int>s;
    for(int i=0; i<n; i++){
        while(arr[i]%2==0){
            s.insert(arr[i]);
            arr[i]/=2;
        }
    }
    cout<<s.size()<<endl;
    return;
}

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        solve(arr, n);
    }
    return 0;
}