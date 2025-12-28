/* https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D

time 2s
You are given an array a of n integers a1, a2,..., an
Your task is to response to the queries like "How many numbers' values are between 1 and r?".

Input
The first line of the input contains n - the length of the array (1 ≤ n ≤ 10^5).
The second line contains n integers a₁, a2, ..., an (−10⁹ ≤ a¡ ≤ 10^9).
The third line contains integer k — the number of queries (1 ≤ k ≤ 10^5).
The following lines contain a pair of integers 1r - query, described above (-10⁹ ≤ ≤ r ≤ 10^9).

Output
The output must consist of k integers-responses for the queries.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int search(int arr[], int n, int s){
    int start=0, end=n-1, ans=-1;
    while(start<=end){
        int mid=(end+start)/2;
        if(arr[mid]<=s){
            ans= mid;
            start= mid+1; 
        }else end= mid-1;
    }
    return ans+1;
}

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr, arr+n);                           // 1 3 4 10 10  1
    int k; cin>>k;

    while(k--){
        int l, r; cin>>l>>r;
        int a= search(arr, n, l-1);
        int b= search(arr, n, r);
        cout<<b-a<<endl;
    }
    return 0;
}