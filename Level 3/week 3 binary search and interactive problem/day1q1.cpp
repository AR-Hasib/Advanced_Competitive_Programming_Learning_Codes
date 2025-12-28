/* https://codeforces.com/problemset/problem/679/A */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

string query(int temp){
    cout<<temp<<endl;
    string x; cin>>x;
    return x;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    vector<int>test={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 4, 9, 25, 49};
    int count=0;
    for(auto it:test){
        if(query(it)=="yes") count++;
        if(count>1){
            cout<<"composite"<<endl;
            return 0;
        } 
    }

    cout<<"prime"<<endl;

    return 0;
}