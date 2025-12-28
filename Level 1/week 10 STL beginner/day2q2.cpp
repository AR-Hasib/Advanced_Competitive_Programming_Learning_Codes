/* https://cses.fi/problemset/task/1640/

time 1s
You are given an array of n integers, and your task is to find two values (at
distinct positions) whose sum is x.

Input
The first input line has two integers n and : the array size and the target sum.
The second line has n integers a₁, 2,..., a: the array values.

Output
Print two integers: the positions of the values. If there are several solutions, you
may print any of them. If there are no solutions, print IMPOSSIBLE.

Constraints
• 1≤n ≤2·10^5
• 1<x, a ≤ 10^9

Example
Input:
48
2751
Output:
24*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, key; cin>>n>>key;
    vector<pair<int, int>>v(n);
    for(int i=0; i<n; i++){
        int a; cin>>a;
        v[i].first=a; v[i].second=i;
    }
    sort(v.begin(), v.begin()+n);

    for(int i=0; i<n-1; i++){
        int x= v[i].first;
        int y= key-x;
        int start= i+1, end= n-1;
        while(start<=end){
            int mid= (start+end)/2;
            if(y == v[mid].first){
                cout<<v[i].second+1<<" "<<v[mid].second+1;
                return 0;
            }else if(y>v[mid].first) start= mid+1;
            else if(y<v[mid].first) end= mid-1;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}