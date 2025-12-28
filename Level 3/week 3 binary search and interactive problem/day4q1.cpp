/* https://codeforces.com/problemset/problem/1167/B */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

int query(int l, int r){
    cout<<"? "<<l<<" "<<r<<endl;
    int x; cin>>x;
    return x;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    set<int>nums={4, 8, 15, 16, 23, 42};
    int ab= query(1, 2);
    int ac= query(1, 3);
    int ad= query(1, 4);
    int ae= query(1, 5);

    int a1, a2, c1, c2;
    int a, b, c, d, e, f;

    for(auto i:nums){
        if(ab%i==0 && nums.find(ab/i)!=nums.end()){
            a1=i;
            a2=ab/i;
        }

        if(ac%i==0 && nums.find(ac/i)!=nums.end()){
            c1=i;
            c2=ac/i;
        }
    }

    if(a1==c1 || a1==c2) a=a1;
    else a=a2;

    b=ab/a;
    c=ac/a;
    d=ad/a;
    e=ae/a;

    for(auto i:nums){
        if(i!=a && i!=b && i!=c && i!=d && i!=e) f=i;
    }

    cout<<"! "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;

    return 0;
}