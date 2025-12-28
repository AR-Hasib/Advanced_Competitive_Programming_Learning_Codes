/* https://atcoder.jp/contests/arc087/tasks/arc087_a

Problem Statement
You are given a sequence of positive integers of length N, a = (a₁, a2, ..., ay). Your objective is to remove some of the elements in a so that a will be a
good sequence.
Here, an sequence b is a good sequence when the following condition holds true:
• For each elemento in b, the value occurs exactly x times in b.
For example, (3, 3, 3), (4, 2, 4, 1, 4, 2, 4) and () (an empty sequence) are good sequences, while (3, 3, 3, 3) and (2, 4, 1, 4, 2) are not.
Find the minimum number of elements that needs to be removed so that a will be a good sequence.

Constraints
time 2s
• 1≤N ≤ 10^5
• ai is an integer.
• 1 ≤ ai < 10⁹

Input
Input is given from Standard Input in the following format:
N
a1 a2 ... aN

Output
Print the minimum number of elements that needs to be removed so that a will be a good sequence.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, cost=0; cin >>n;
    int arr[n+1];
    for(int i=0; i<n; i++) cin>>arr[i];
    arr[n]=0;
    sort(arr, arr+n);

    int current=arr[0], count=1;
    for(int i=1; i<=n; i++){
        if(arr[i]==current){
            count++;
        }else{
            if(current>count) cost+= count;
            else if(current<count) cost+= count-current;
            current= arr[i];
            count= 1;
        }
    }
    cout<<cost;
    return 0;
}