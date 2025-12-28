/* https://atcoder.jp/contests/abc258/tasks/abc258_a 

AtCoder Beginner Contest usually starts at 21:00 JST and lasts for 
100 minutes.

You are given an integer K between 0 and 100 (inclusive).
Print the time K minutes after 21:00 in the HH:MM format, where HH denotes the hour on the  24-hour clock and MM denotes the minute. If the hour or the minute has just one digit, append a 
0 to the beginning to represent it as a 2-digit integer.

Sample Input 1
63

Sample Output 1
22:03
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int k, h=21, m=0; cin>>k;

    if(k>=60){
        m=k-60;
        h+=(k/60);
        if(m<10) cout<<h<<":0"<<m;
        else cout<<h<<":"<<m;
    }else{
        m=k;
        if(m<10) cout<<h<<":0"<<m;
        else cout<<h<<":"<<m;
    }

    return 0;
}