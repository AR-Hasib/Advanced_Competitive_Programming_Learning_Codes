/* https://codeforces.com/problemset/problem/1676/B

There are n boxes with different quantities of candies in each of them. The i-th box has a; candies inside.
You also have n friends that you want to give the candies to, so you decided to give each friend a box of candies. But, you don't want any
friends to get upset so you decided to eat some (possibly none) candies from each box so that all boxes have the same quantity of candies
in them. Note that you may eat a different number of candies from different boxes and you cannot add candies to any of the boxes.
What's the minimum total number of candies you have to eat to satisfy the requirements?

Input
The first line contains an integer t (1 ≤ t ≤ 1000) - the number of test cases.
The first line of each test case contains an integer n (1 ≤ n ≤ 50) - the number of boxes you have.
The second line of each test case contains n integers a₁, a2, ..., an (1 ≤ ai ≤ 10^7) — the quantity of candies in each box.

Output
For each test case, print a single integer denoting the minimum number of candies you have to eat to satisfy the requirements.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        int n; cin>>n;
        int arr[n], mn=INT_MAX, sum=0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            sum+=arr[i];
            mn= min(mn, arr[i]);
        } 
        cout<<sum-(mn*n)<<endl;
    }
    return 0;
}