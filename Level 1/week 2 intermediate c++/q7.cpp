/* https://codeforces.com/problemset/problem/1367/B 

You are given an array a[0…n−1] of length n which consists of non-negative integers. Note that array indices start from zero.

An array is called good if the parity of each index matches the parity of the element at that index. More formally, an array is good if for all i (0≤i≤n−1) the equality i mod 2 = a[i]mod 2 holds, where x mod 2 is the remainder of dividing xby 2.

For example, the arrays [0,5,2,1] and [0,17,0,3] are good, and the array [2,4,6,7] is bad, because for i=1, the parities of i and a[i] are different: imod2=1mod2=1, but a[i]mod2=4mod2=0

In one move, you can take any two elements of the array and swap them (these elements are not necessarily adjacent).
Find the minimum number of moves in which you can make the array agood, or say that this is not possible.

Input
The first line contains a single integer t(1≤t≤1000) — the number of test cases in the test. Then test cases follow.
Each test case starts with a line containing an integer n(1≤n≤40) — the length of the array a.
The next line contains nintegers a0,a1,…,an−1 (0≤ai≤1000) — the initial array.

Output
For each test case, output a single integer — the minimum number of moves to make the given array a good, or -1 if this is not possible */

#include<bits/stdc++.h>
using namespace std;

int main(){

    int t, n; cin>>t;
    while(t--){
        cin>>n;
        int arr[n];

        int count0= 0, count0i= 0, count1= 0, count1i= 0;

        for(int i=0; i<n; i++){
            cin>>arr[i];

            if((arr[i]%2) != (i%2) ){

                if((arr[i]%2)==0) ++count0;
                else ++count1;

                if((i%2)==0) ++count0i;
                else ++count1i;
            } 
        }
        
        if(count0==count0i && count1==count1i){
            cout<<count0<<endl;
        }else cout<<"-1"<<endl;
     
    }
    return 0;
}