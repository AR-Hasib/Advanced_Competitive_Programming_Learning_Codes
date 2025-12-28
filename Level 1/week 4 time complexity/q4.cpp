/* https://atcoder.jp/contests/abc251/tasks/abc251_b

Problem Statement
There are N weights called Weight 1, Weight 2, ..., Weight N. Weight i has a mass of Aį.
Let us say a positive integer n is a good integer if the following condition is satisfied:
• We can choose at most 3 different weights so that they have a total mass of n.
How many positive integers less than or equal to W are good integers?

Constraints
• 1 ≤ N≤ 300
• 1≤W ≤ 106
1 ≤ A ≤ 106
All values in input are integers.

Input
Input is given from Standard Input in the following format:
N W
A₁ A2 .... AN
Output
Print the answer.*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, w; cin>>n>>w;
    int arr[n]; 
    for(int i=0; i<n; i++) cin>>arr[i];

    int mx= w+1;
    int cnt[mx];
    for(int i=0; i<mx; i++) cnt[i]=0;
    int count=0;

    for(int i=0; i<n; i++){
        int x= arr[i];
        if(x<=w){
            if(cnt[x]==0) count++; 
            cnt[x]++;
        } 
    }

   for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int y= arr[i]+arr[j];
            if(y<=w){
                if(cnt[y]==0) count++; 
                cnt[y]++;
            } 
        }
    }  
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                int z= arr[i]+arr[j]+arr[k];
                if(z<=w){
                    if(cnt[z]==0) count++; 
                    cnt[z]++;
                } 
            }
        }
    }

    cout<<count;
    return 0;
}