/* https://codeforces.com/problemset/problem/1406/A

Given a set of integers (it can contain equal elements).
You have to split it into two subsets A and B (both of them can contain equal elements or be empty). You have to maximize the value of
mex (A) +mex(B).
Here mex of a set denotes the smallest non-negative integer that doesn't exist in the set. For example:
•mex({1, 4, 0, 2, 2, 1}) = 3
•mex({3, 3, 2, 1, 3, 0, 0}) = 4
mex (0) = 0 (mex for empty set)

The set is splitted into two subsets A and B if for any integer number the number of occurrences of into this set is equal to the sum of
the number of occurrences of a into A and the number of occurrences of a into B.

Input
The input consists of multiple test cases. The first line contains an integer t (1 ≤ t ≤ 100) - the number of test cases. The description of
the test cases follows.
The first line of each test case contains an integer n (1 ≤ n ≤ 100)- the size of the set.
The second line of each testcase contains n integers a₁, a2, ... an (0 ≤ai ≤ 100) - the numbers in the set.

Output
For each test case, print the maximum value of mex(A) +mex(B).
*/

/*
approach: 
mexA will be the smallest number which is included 0 or 1 time in the set
nexB ..... 0 time ...... 
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        int arr[n], cnt[101];
        for(int i=0; i<101; i++) cnt[i]=0;

        for(int i=0; i<n; i++){
            cin>>arr[i];
            cnt[arr[i]] +=1;
        }

        int a=0, b=0;
        for(int i=0; i<101; i++){
            if(cnt[i] == 1 || cnt[i] == 0) {
                a=i;
                break;
            }
        }
        for(int i=0; i<101; i++){
            if(cnt[i] == 0) {
                b=i;
                break;
            }
        }

        cout<<a+b<<endl;
    }

    return 0;
}