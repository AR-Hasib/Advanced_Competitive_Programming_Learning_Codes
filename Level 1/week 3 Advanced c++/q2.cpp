/* https://atcoder.jp/contests/abc263/tasks/abc263_a

We have five cards with integers A, B, C, D, and E written on them, one on each card.

This set of five cards is called a Full house if and only if the following condition is satisfied:

the set has three cards with a same number written on them, and two cards with another same number written on them.
Determine whether the set is a Full house.

Constraints
1≤A,B,C,D,E≤13
Not all of A, B, C, D, and E are the same.
All values in input are integers.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[5], a=0, b=0, countA=0, countB=0;

    for(int i=0; i<5; i++){
        cin>>arr[i];
    }

    a= arr[0];
    for(int i=1; i<5; i++){
        if(arr[i]!=a){
            b= arr[i];
            break;
        }
    }

    for(int i=0; i<5; i++){
        if(arr[i]==a) countA++;
        if(arr[i]==b) countB++;
    }

    if((countA==3 && countB==2) || (countA==2 && countB==3)) cout<<"Yes";
    else cout<<"No";

    return 0;
}