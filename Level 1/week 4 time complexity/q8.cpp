#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    // we have to solve faster than O(n)
    int t; cin >> t;
    while (t--) {
        int count=0;
        int z; cin>>z;
        for(int i=1; i<=sqrt(z); i++){
            if(z%i == 0){
               count++; 
               if(z/i != i) count++;
            } 
        }
        cout<<count<<endl;
    }
    return 0;
}