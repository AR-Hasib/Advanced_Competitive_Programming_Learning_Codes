/* https://codeforces.com/contest/1808/problem/B

Galaxy Luck, a well-known casino in the entire solar system, introduces a new card game.
In this game, there is a deck that consists of n cards. Each card has m numbers written on it. Each of the n players receives exactly one
card from the deck.
Then all players play with each other in pairs, and each pair of players plays exactly once. Thus, if there are, for example, four players in
total, then six games are played: the first against the second, the first against the third, the first against the fourth, the second against the
third, the second against the fourth and the third against the fourth.
Each of these games determines the winner in some way, but the rules are quite complicated, so we will not describe them here. All that
matters is how many chips are paid out to the winner. Let the first player's card have the numbers a₁, a2,..., am, and the second player's
card-b₁,b₂,..., bm. Then the winner of the game gets |a₁ − b₁| + |a2 − b₂| + ··· + |am - bm| chips from the total pot, where |x|
denotes the absolute value of x.
To determine the size of the total pot, it is necessary to calculate the winners' total winnings for all games. Since there can be many cards in
a deck and many players, you have been assigned to write a program that does all the necessary calculations.

Input
Each test consists of several test cases. The first line contains one integer t (1 ≤ t ≤ 1000) - the number of test cases. The description
of the test cases follows.
The first line of each test case contains two integers n and m (1 ≤ n · m ≤ 3 · 10^5) — the number of cards in the deck and the count of
numbers on the one card.
Each of the following n lines of the test case set contains m integers Cij (1 ≤ Cij ≤ 10^6).
) - a description the i-th card.
It is guaranteed that the total n. m in all tests does not exceed 3. 10^5.

Output
For each test case, print one number the total amount of winnings from all games.
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while ( t--)
    {
       int n,m;cin>>n>>m;
       vector<int>v[m];
       for ( int i = 0; i <  n; i++)
       {
         for ( int j = 0; j <  m; j++)
         {
             int x;cin>>x;
             v[j].push_back(x);
         }
       }

       for(int i=0;i<m;i++){
        sort(v[i].begin(),v[i].end());
       }

       int ans=0;
       for(int i=0;i<m;i++){
        vector<int>res(n,0);
        res[n-1]=v[i][n-1];
        for(int j=n-2;j>=0;j--){
            res[j]=res[j+1]+v[i][j];
        }

        for(int j=0;j<n-1;j++){
            int cnt=res[j+1]-(n-1-j)*v[i][j];
            ans+=cnt;
        }
     }
       cout<<ans<<endl;
       
    }

}