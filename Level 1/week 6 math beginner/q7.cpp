/* https://codeforces.com/problemset/problem/898/B

Vasya has n burles. One bottle of Ber-Cola costs a burles and one Bars bar costs b burles.
He can buy any non-negative integer number of bottles of Ber-Cola and any non-negative integer number of Bars bars.
Find out if it's possible to buy some amount of bottles of Ber-Cola and Bars bars and spend exactly n burles.

In other words, you should find two non-negative integers x and y such that Vasya can buy x bottles of Ber-Cola and 
y Bars bars and x·a + y·b = n or tell that it's impossible.

Input
First line contains single integer n (1 ≤ n ≤ 10 000 000) — amount of money, that Vasya has.

Second line contains single integer a (1 ≤ a ≤ 10 000 000) — cost of one bottle of Ber-Cola.

Third line contains single integer b (1 ≤ b ≤ 10 000 000) — cost of one Bars bar.

Output
If Vasya can't buy Bars and Ber-Cola in such a way to spend exactly n burles print «NO» (without quotes).

Otherwise in first line print «YES» (without quotes). In second line print two non-negative integers x and
y — number of bottles of Ber-Cola and number of Bars bars Vasya should buy in order to spend exactly n burles, 
i.e. x·a + y·b = n. If there are multiple answers print any of them.

Any of numbers x and y can be equal 0.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, a, b; cin>>n>>a>>b;
    int x=0; bool flag=false;
    while(x*a<=n){
        double y= (double(n-x*a)/b);
        if(y == floor(y)){
            cout<<"YES"<<endl;
            cout<<x<<" "<<int(y)<<endl;
            flag= true;
            break;
        }
        x++;
    }
    if(flag== false) cout<<"NO"<<endl;
    return 0;
}