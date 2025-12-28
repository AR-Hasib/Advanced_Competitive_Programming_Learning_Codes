/*https://codeforces.com/problemset/problem/660/A

You are given an array of n elements, you must make it a co-prime array in as few moves as possible.
In each move you can insert any positive integral number you want not greater than 109 in any place in the array.
An array is co-prime if any two adjacent numbers of it are co-prime.
In the number theory, two integers a and b are said to be co-prime if the only positive integer that divides both of them is 1.

Input
The first line contains integer n (1 ≤ n ≤ 1000) — the number of elements in the given array.
The second line contains n integers ai (1 ≤ ai ≤ 109) — the elements of the array a.

Output
Print integer k on the first line — the least number of elements needed to add to the array a to make it co-prime.
The second line should contain n + k integers aj — the elements of the array a after adding k elements to it. Note that 
the new array should be co-prime, so any two adjacent values should be co-prime. Also the new array should be got from the 
original array a by adding k elements to it.
If there are multiple answers you can print any one of them.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    vector<int>s;

    for(int i=0; i<n-1; i++){
        s.emplace_back(arr[i]);
        if(__gcd(arr[i], arr[i+1]) != 1) s.emplace_back(1);
    }
    s.emplace_back(arr[n-1]);
    cout<<s.size()-n<<endl;
    for (int i : s) {
        cout <<i<<" ";
    }
    return 0;
}