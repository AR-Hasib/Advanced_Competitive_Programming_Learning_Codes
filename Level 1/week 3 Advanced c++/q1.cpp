/* https://atcoder.jp/contests/abc305/tasks/abc305_a

There is an ultramarathon course totaling 100km. Water stations are set up every 5km along the course, including the start and goal, for a total of 21.

Takahashi is at the Nkm point of this course. Find the position of the nearest water station to him.

Under the constraints of this problem, it can be proven that the nearest water station is uniquely determined.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int x= n%5;

    if(x>2) cout<<(n+(5-x));
    else cout<<(n-x);

    return 0;
}