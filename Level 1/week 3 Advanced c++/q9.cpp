/* https://atcoder.jp/contests/abc303/tasks/abc303_b

N people numbered 1,2,…,N were in M photos. In each of the photos, they stood in a single line. In the i-th photo, the j-th person from the left is person aij

Two people who did not stand next to each other in any of the photos may be in a bad mood.

How many pairs of people may be in a bad mood? Here, we do not distinguish a pair of person x and person y, and a pair of person y and person x.

Constraints
2≤ N ≤50
1≤ M ≤50
1≤ aij ≤N

ai1,…,aiN contain each of 1,…,N exactly once.
All values in the input are integers.

 */

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m; cin>>n>>m;
    int arr[m][n];

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    int i=0, x=0, count=0;
    for(int j=0; j<n-2; j++){
        for(int k=j+2; k<n; k++){
            x=0;
            int a=arr[i][j], b=arr[i][k];
            for(int p=1; p<m; p++){
                for(int q=0; q<n-1; q++){
                    if(arr[p][q]==a){
                        if(arr[p][q+1]==b) x++;
                    }else if(arr[p][q]==b){
                        if( arr[p][q+1]==a) x++;
                    }
                }
            }
            if(x==0) count++;
        }
    }

    cout<<count;

    return 0;
}