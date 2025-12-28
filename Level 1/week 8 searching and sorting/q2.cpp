/* https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B

Given an array of n numbers, sorted in non-decreasing order, and k queries. For each query, print the maximum index of an array element
not greater than the given one.
Input
The first line of the input contains integers n and k (0 < n, k ≤ 10^5), the length of the array and the number of queries. The second line
contains n elements of the array, sorted in non-decreasing order. The third line contains k queries. All array elements and queries are
integers, each of which does not exceed 2 - 10^9 in absolute value.
Output
For each of the k queries, print the maximum index of an array element not greater than the given one. If there are none, print 0.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

int search(int arr[], int n, int key){
    int ans=-1;
    int start=0, end=n-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]<=key){
            ans= mid;
            start= mid+1;
        }else end= mid-1;
    }
    return ans+1;
}

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k; cin>>n>>k;
    int arr[n], s[k];
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<k; i++){
        cin>>s[i];
        cout<<search(arr, n, s[i])<<endl;
    } 
    return 0;
}