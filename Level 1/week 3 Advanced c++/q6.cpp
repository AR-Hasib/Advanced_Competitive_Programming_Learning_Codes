/* https://atcoder.jp/contests/abc309/tasks/abc309_b 

rotate the outer square of n*n 2d matrix clock-wise 
input 
n
n line of only 0 or 1

example 
input:
3
110
011
101

output:
011
110
011
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin>>n;
    int a[n][n];

//identifying the input and input to array
    for(int i=0; i<n; i++){

    // if input is a string
        string s;
        cin>>s;
        for(int j=0; j<n; j++){
            a[i][j]= int(s[j])-int('0');
        }

    // if input is an integer
        // int x; cin>>x;
        // for(int j=n-1; j>=0; j--){
        //     a[i][j]= x%10;
        //     x/=10;
        // }
    }

//main operation
    int temp;
    for(int i=0; i<n; i++){
        if(i==0){
            temp= a[i][n-1];
            for(int j=n-1; j>=0; j--){
                if(j==0){
                    a[i][j]= a[i+1][j];
                }else{
                    a[i][j]= a[i][j-1];
                }
            }
        }else if(i==n-1){
            for(int j=0; j<n; j++){
                if(j==n-1){
                    a[i][j]= temp;
                }else{
                    a[i][j]= a[i][j+1];
                }
            }
        }else{
            a[i][0]= a[i+1][0];
            int temp1= a[i][n-1];
            a[i][n-1]= temp;
            temp= temp1;
        }
    }

//output
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }

    return 0;
}