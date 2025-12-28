/*https://codeforces.com/contest/1174/problem/A

You're given an array a of length 2n. Is it possible to reorder it in such way so that the sum of the first n elements isn't equal to the sum of
the last n elements?

Input
The first line contains an integer n (1 ≤ n ≤ 1000), where 2n is the number of elements in the array a.
The second line contains 2n space-separated integers a₁, a2, ..., α2n (1 ≤ ai ≤ 106) — the elements of the array a.

Output
If there's no solution, print "-1" (without quotes). Otherwise, print a single line containing 2n space-separated integers. They must form a
reordering of a. You are allowed to not change the order.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

void print(int arr[], int n){
    for(int i=0; i<2*n; i++) cout<<arr[i]<<" ";
    return;
}

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    int arr[2*n]; bool flag=false;
    for(int i=0; i<2*n; i++){
        cin>>arr[i];
    } 
    
    int a= arr[0];
    for(int i=1; i<2*n; i++){
        if(arr[i]!=a){
            flag= true;
            break;
        }
    }
    if(flag == false) cout<<"-1";
    else{
        sort(arr, arr+2*n);
        print(arr, n);
    }

    return 0;
}