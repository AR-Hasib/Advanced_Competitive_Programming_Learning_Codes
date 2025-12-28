/* https://www.hackerrank.com/challenges/number-groups/problem

The positive odd numbers are sorted in ascending order as 1, 3, 5, 7, 9, 11, 13, 15, 17, 19..., and grouped as
(1), (3,5), (7, 9, 11), (13, 15, 17, 19),... and so on.
Thus, the first group is (1), the second group is (3,5), the third group is (7, 9, 11), etc. In general, the kth group contains the
next k elements of the sequence.
Given k, find the sum of the elements of the kth group. For example, for k= 3, the answer is 27:

k=3
7 + 9 + 11 = 27
Complete the function sumOfGroup with input integer k. Return the sum of the elements of the kth group.

Constraints
1 ≤ k < 106
Subtasks
• For 50% of the maximum score, k < 10³

Sample Input
k = 3

Sample Output
27

Explanation
We have k = 3. The 3rd group is (7, 9, 11) and the sum of its elements is 7+9+ 11 = 27.
 */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int k; cin >> k;

    int a= (k*(k-1))/2; // sum of 1 to k-1th , so a+1th odd number will be the firs number of kth group
    int b= 2*(a+1)-1;
    int sum=0;

    for(int i=1; i<=k; i++){
        sum+=b;
        b+=2;
    }

    cout<<sum;
}