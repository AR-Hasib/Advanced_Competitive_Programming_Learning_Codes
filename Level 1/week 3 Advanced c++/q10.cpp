/* https://atcoder.jp/contests/abc300/tasks/abc300_b

Takahashi is developing an RPG. He has decided to write a code that checks whether two maps are equal.

We have grids A and B with H horizontal rows and W vertical columns. Each cell in the grid has a symbol # or . written on it.
The symbols written on the cell at the 
i-th row from the top and j-th column from the left in A and B are denoted by Ai,j and Bi,j, respectively.

The following two operations are called a vertical shift and horizontal shift.

For each j=1,2,…,W, simultaneously do the following:
simultaneously replace A1,j ,A2,j ,…,AH−1,j ,AH,j with A2,j ,A3,j ,…,A H,j ,A 1,j .

For each i=1,2,…,H, simultaneously do the following:
simultaneously replace A i,1 ,Ai,2 ,…,Ai,W−1 ,Ai,W with A i,2,A i,3,…,Ai,W ,Ai,1.
Is there a pair of non-negative integers (s,t) that satisfies the following condition? Print Yes if there is, and No otherwise.

After applying a vertical shift s times and a horizontal shift t times, A is equal to B.
Here, A is said to be equal to B if and only if 
A i,j =B i,j for all integer pairs (i,j) such that 1≤i≤H and 1≤j≤W.

Constraints
2≤H,W≤30
A i,j is # or ., and so is B i,j .
H and W are integers. */

#include<bits/stdc++.h>
using namespace std;

int main(){

    string str; int h, w; cin>>h>>w;
    int arr[h][w], brr[h][w];
    
    for(int i=0; i<h; i++){
        cin>>str;
        for(int j=0; j<w; j++){
            if(str[j]=='.') arr[i][j]= 0;
            else arr[i][j]= 1;
        }
    }
    for(int i=0; i<h; i++){
        cin>>str;
        for(int j=0; j<w; j++){
            if(str[j]=='.') brr[i][j]= 0;
            else brr[i][j]= 1;
        }
    }

    for(int s=0; s<h; s++){
        for(int t=0; t<w; t++){
            bool flag= true;

            //checking the elements whether it is equal or not
            for(int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                    if(arr[i][j] != brr[(i+s)%h][(j+t)%w]){
                        flag= false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag){
                cout<<"Yes";
                return 0;
            }
        }
    }

    cout<<"No";

    return 0;
}