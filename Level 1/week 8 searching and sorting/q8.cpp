/* https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

An array arr is a mountain if the following properties hold:
. arr.length >= 3
. There exists some i with 0 < i < arr.length - 1 such that:
• arr[0] < arr[1]...< arr[i − 1] < arr[i]
. arr[i] > arr[i + 1] > ... > arr[arr. length - 1]

Given a mountain array arr, return the index i such that arr [0] < arr[1] < ... < arr[i − 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
******** You must solve it in 0(log(arr.length)) time complexity.
Example 1:
Input: arr = [0,1,0]
Output: 1

Example 2:
Input: arr = [0,2,1,0]
Output: 1

Example 3:
Input: arr = [0,10,5,2]
Output: 1

Constraints:
3 <= arr.length <= 105
0 <= arr[i] <= 106
arr is guaranteed to be a mountain array.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

int peakIndexInMountainArray(vector<int>& arr) {
    int s=1, e=arr.size()-1, mid;
    while(s<=e){
        mid= (s+e)/2;
        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]) break;
        else if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]) s= mid+1;
        else if(arr[mid-1]>arr[mid] && arr[mid]>arr[mid+1]) e= mid-1;
    }
    return mid;
}

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    vector<int>arr;
    while (t--) {
        int n; cin>>n;
        arr.emplace_back(n);
    }
    cout<<peakIndexInMountainArray(arr);
    return 0;
}