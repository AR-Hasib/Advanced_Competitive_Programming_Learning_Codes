/* https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

bool possible(int time, int n, int x, int y){
    time-=x;    n--;    // 1st copy. then we can start both copier
    if(time<0) return false;
    int copy=(time/x)+(time/y);
    return copy>=n;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, x, y; cin>>n>>x>>y;

    if(x>y) swap(x, y); // make sure x is lesser
    int left=0, right=n*x; // making a time axis
    int result=right;

    while(left<=right){
        int mid= (left+right)/2;
        if(possible(mid, n, x, y)){
            result=mid;
            right=mid-1;
        }else left=mid+1;
    }
    cout<<result;

    return 0;
}