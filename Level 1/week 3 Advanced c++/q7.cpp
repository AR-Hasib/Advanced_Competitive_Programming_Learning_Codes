/* https://atcoder.jp/contests/abc301/tasks/abc301_b 

fill the gaps */

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<arr[0]<<" ";
    for(int i=1; i<n; i++){
        if(arr[i-1]<arr[i]){
            for(int j=arr[i-1]+1; j<arr[i]; j++){
            cout<<j<<" ";
            }
        }else if(arr[i-1]>arr[i]){
            for(int j=arr[i-1]-1; j>arr[i]; j--){
            cout<<j<<" ";
            }
        }
        cout<<arr[i]<<" ";
    }

    return 0;
}