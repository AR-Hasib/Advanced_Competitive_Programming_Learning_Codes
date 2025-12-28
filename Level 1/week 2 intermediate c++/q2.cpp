/* Given a number N. The task is to print a series of asterisk(*) from 1 till N terms with increasing order and difference being 1. */

#include<bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin>>N;

    for(int i=1; i<=N; i++){
            for(int j=1; j<=i; j++){
                cout<<"*";
            }
            cout<<" ";
        }

    return 0;
}