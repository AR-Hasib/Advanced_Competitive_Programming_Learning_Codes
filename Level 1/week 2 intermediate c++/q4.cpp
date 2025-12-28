/* https://www.hackerearth.com/problem/golf/print-the-pattern/

Given an integer n(1<=n<=10), print n rows of the given pattern in minimum length.
1
2 3
6 5 4
7 8 9 10
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;  cin>>n;
    int count=1;

    for(int i=1; i<=n; i++){
        for(int j=i; j>=1; j--){
            if(i%2==0){
                cout<<count<<" ";
                count++;
            }else{
                cout<<count+j-1<<" ";
                if(j==1){
                    count+= i;
                }
            }
        }
        cout<<endl;
    }

    return 0;
}