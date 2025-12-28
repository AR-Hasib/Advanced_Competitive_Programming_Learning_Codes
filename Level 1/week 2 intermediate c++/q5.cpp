/* https://practice.geeksforgeeks.org/problems/pattern/1

if input 4
output: 
   *
  * *
 * * *
* * * * 
* * * *
 * * *
  * *
   *   
     
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; cin>>n;

    for(int i=1; i<=n; i++){
        for(int k=i; k<n; k++){
            cout<<" ";
        }
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=n; i>=1; i--){
        for(int k=i; k<n; k++){
            cout<<" ";
        }
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    return 0;
}
