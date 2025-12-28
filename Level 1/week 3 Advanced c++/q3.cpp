/* https://codeforces.com/problemset/problem/271/A

It seems like the year of 2013 came only yesterday. Do you know a curious fact? The year of 2013 is the first year after the old 1987 with only distinct digits.

Now you are suggested to solve the following problem: given a year number, find the minimum year number which is strictly larger than the given one and has only distinct digits.

Input
The single line contains integer y (1000 ≤ y ≤ 9000) — the year number.

Output
Print a single integer — the minimum year number that is strictly larger than y and all it's digits are distinct. It is guaranteed that the answer exists.*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin>>n;
    int arr[4];

    for(int i=n+1; ; i++){
        int x= i;
        arr[0]= x%10;
        x/=10;
        arr[1]= x%10;
        x/=10;
        arr[2]= x%10;
        x/=10;
        arr[3]= x;

        int p= 0;

        for(int j=0; j<4; j++){
            for(int k=j+1; k<4; k++){
                if(arr[j]==arr[k]){
                    p++ ;
                    break;
                } 
            }
        }

        if(p==0){
            cout<<i;
            break;
        }
    }

    return 0;
}