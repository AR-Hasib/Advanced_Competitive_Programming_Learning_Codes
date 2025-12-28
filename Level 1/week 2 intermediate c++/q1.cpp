/* Given a number N and two arrays A, B of N numbers. Determine if B is a permutation of A or not.

Note: A permutation is an arrangement of all or part of a set of objects.

For example: The array [2, 1, 3], [3, 2, 1] and [2, 3, 1] are permutation of the array [1, 2, 3].

Input
First line contains a number N (1≤N≤10^3) Number of elements.
Second line contains N numbers (1≤Ai≤10^7) elements of array A
Third line contains N numbers (1≤Bi≤10^7) elements of array B

Output
Print "yes" if array B is a permutation of A. otherwise, print "no" without quotations. */

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int a[n], b[n];

    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    
    sort(a, a+n);
    sort(b, b+n);

   for(int i=0; i<n; i++){
        if(a[i]!=b[i]){
            cout<<"no";
            return 0;
        }
   }
   cout<<"yes";

    return 0;
}