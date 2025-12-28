/* https://cses.fi/problemset/task/1141/

time 1s
You are given a playlist of a radio station since its establishment. The playlist has a total of n songs.
What is the longest sequence of successive songs where each song is unique?

Input
The first input line contains an integer n: the number of songs.
The next line has n integers k_1,k_2,.....,k_n: the id number of each song.

Output
Print the length of the longest sequence of unique songs.
Constraints

1 <= n <= 2*10^5
1 <= k_i <= 10^9

Example
Input:
8
1 2 1 3 2 7 4 2

Output:
5
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    map<int, int>mp;
    int ans=0, start=0;
    
    for(int i=0; i<n; i++){
        if(mp.count(arr[i])) start= max(start, mp[arr[i]]+1);
        mp[arr[i]]=i;
        ans= max(ans, i-start+1);
    }

    cout<<ans;

    return 0;
}