/*
https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/Z

Given two numbers K and S. Determine how many different values of X,Y and Z such that (0≤X,Y,Z≤K) and X+Y+Z=S.

Input
Only one line containing two numbers K and S(0≤K≤3000,0≤S≤3K)

Output
Print the answer required above.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){

    int k, s; cin>>k>>s;
    int count=0;

    for(int a=0; a<=k; a++){
       for(int b=0; b<=k; b++){
        int z=s-a-b;
        if(z>=0 && z<=k) count++;
       }
    }
    cout<<count;
        return 0;
}