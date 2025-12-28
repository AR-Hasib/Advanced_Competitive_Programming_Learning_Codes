/* https://codeforces.com/problemset/problem/1705/B

Mark is cleaning a row of n rooms. The i-th room has a nonnegative dust level a. He has a magical cleaning machine that can do the
following three-step operation.
• Select two indices i<j such that the dust levels ai, ai+1¹ aj 1 are all strictly greater than 0.
• Set ai to a₁ - 1.
• Set a, to aj + 1.
Mark's goal is to make a₁ = a₂ =..=an-1 = 0 so that he can nicely sweep the n-th room. Determine the minimum number of
operations needed to reach his goal.

Input
The first line contains a single integert (1 < t ≤ 10¹) — the number of test cases.
The first line of each test case contains a single integer n (2 ≤ n ≤2.105) - the number of rooms.
The second line of each test case contains n integers a₁, A2,. an (0 ≤ ai ≤ 10⁹) — the dust level of each room.
It is guaranteed that the sum of n across all test cases does not exceed 2. 105.

Output
For each test case, print a line containing a single integer the minimum number of operations. It can be proven that there is a sequence
of operations that meets the goal.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int t; cin>>t;

    while(t--){
        bool flag= false;
        long long int n; cin>>n;
        long long int arr[n]; 
        for(long long int i=0; i<n; i++){
            cin>>arr[i];
        }   

        long long int sum=0;
        for(long long int j=0; j<n-1; j++){
            if(arr[j] != 0) flag= true;
            if(arr[j] == 0 && flag == true) sum+=1;
            sum+=arr[j];
        }
        cout<<sum<<endl;
   }
    return 0;
}