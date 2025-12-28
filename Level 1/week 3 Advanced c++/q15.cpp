/*
https://codeforces.com/problemset/problem/1405/B

You're given an arraya of n integers, such that a₁ + a₂ +
In one operation, you can choose two different indices ¿ and j (1 ≤ i, j ≤ n), decrement a; by one and increment a; by one. If i < j
this operation is free, otherwise it costs one coin.
How many coins do you have to spend in order to make all elements equal to 0?

Input
Each test contains multiple test cases. The first line contains the number of test cases # (1 ≤t <5000). Description of the test cases
follows.

The first line of each test case contains an integer n (1 ≤ n ≤ 10^5) — the number of elements.
The next line contains n integers a₁,..., an (−10⁹ ≤ ai ≤ 10³). It is given that (i=1 n)∑ ai=0

It is guaranteed that the sum of n over all test cases does not exceed 10^5.

Output
For each test case, print the minimum number of coins we have to spend in order to make all elements equal to 0.
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
        int n, sum=0; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];

        int pos=0, neg=0;

        for(int i=0; i<n; i++){
            if(arr[i]>=0){
                pos += arr[i];
            }else{
                if(pos >= abs(arr[i])){
                    pos += arr[i];
                }else{
                    neg = neg + abs(arr[i]) - pos;
                    pos = 0;
                }
            }
        }
        
        cout<<neg<<endl;
    }
}