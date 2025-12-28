/* https://codeforces.com/problemset/problem/122/A

Petya loves lucky numbers. Everybody knows that lucky numbers are positive integers whose decimal representation contains only the lucky digits 4 and 7.
For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Petya calls a number almost lucky if it could be evenly divided by some lucky number. Help him find out if the given number n is almost lucky.

Input
The single line contains an integer n (1 ≤ n ≤ 1000) — the number that needs to be checked.

Output
In the only line print "YES" (without the quotes), if number n is almost lucky. Otherwise, print "NO" (without the quotes).
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void check(int n){
    int arr[4];
    int i=0, m;
    while(n>0){
        arr[i] = n%10;
        n/=10;
        m=i;
        i++;
    }
    bool flag=true;
    for(int i=0; i<=m; i++){
        if(arr[i]==4 || arr[i]==7){
            continue;
        }else{
            flag= false;
            break;
        }
    }
    if(flag == true){
        cout<<"YES";
        exit(0);
    } 
}
signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    check(n);
    for(int i=4; i<n; i++){
        if(n%i==0){
            check(i);
        }
    }
    cout<<"NO";
    return 0;
}