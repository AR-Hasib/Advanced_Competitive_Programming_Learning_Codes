/* https://codeforces.com/problemset/problem/1472/D

During their New Year holidays, Alice and Bob play the following game using an array a of n integers:
• Players take turns, Alice moves first.
• Each turn a player chooses any element and removes it from the array.
• If Alice chooses even value, then she adds it to her score. If the chosen value is odd, Alice's score does not change.
Similarly, if Bob chooses odd value, then he adds it to his score. If the chosen value is even, then Bob's score does not change.
If there are no numbers left in the array, then the game ends. The player with the highest score wins. If the scores of the players are equal,
then a draw is declared.

For example, if n = 4 and a = [5, 2, 7, 3], then the game could go as follows (there are other options):
On the first move, Alice chooses 2 and get two points. Her score is now 2. The array a is now [5, 7, 3].
• On the second move, Bob chooses 5 and get five points. His score is now 5. The array a is now [7,3].
• On the third move, Alice chooses 7 and get no points. Her score is now 2. The array a is now [3].
• On the last move, Bob chooses 3 and get three points. His score is now 8. The array a is empty now.
• Since Bob has more points at the end of the game, he is the winner.
You want to find out who will win if both players play optimally. Note that there may be duplicate numbers in the array.

Input
The first line contains an integer t (1 ≤ t ≤ 10^4) — the number of test cases. Then t test cases follow.
The first line of each test case contains an integer n (1 ≤ n ≤2·10^5) — the number of elements in the array a.
The next line contains n integers a₁, a2, ..., an (1 ≤ ai ≤ 10⁹) — the array a used to play the game.
It is guaranteed that the sum of n over all test cases does not exceed 2. 10^5.

Output
For each test case, output on a separate line:
• "Alice" if Alice wins with the optimal play;
• "Bob" if Bob wins with the optimal play;
"Tie", if a tie is declared during the optimal play.
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
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];

        sort(arr, arr+n);
        int bob=0, alice=0, count=0;
        for(int i=n-1; i>=0; i--){
            if(count%2==0){
                if(arr[i]%2==0) alice+=arr[i];
            }else{
                if(arr[i]%2!=0) bob+=arr[i];
            }
            count++;
        }
        if(bob==alice) cout<<"Tie"<<endl;
        else if(bob>alice) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
    return 0;
}