/* https://codeforces.com/contest/1889/problem/A */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    int n; string s; cin>>n>>s;

    // if count of 0 and 1 are not same, it is impossible
    int c0=0, c1=0;
    for(auto i:s){
        if(i=='0') c0++;
        else c1++;
    }
    if(c0!=c1){
        cout<<-1<<endl;
        return;
    }

    // now it is possible
    vector<int>ans;
    deque<char>a;
    // copy the string to deque
    for(auto i:s) a.push_back(i);

    int d=0;
    while(!a.empty()){
        if(a.front()==a.back()){
            if(a.front()=='0'){
                a.push_back('0');
                a.push_back('1');
                ans.push_back(n-d);
            }else{
                a.push_front('1');
                a.push_front('0');
                ans.push_back(d);
            }
            n+=2;
        }
        while(!a.empty() && a.front()!=a.back()){
            a.pop_back();
            a.pop_front();
            ++d;
        }
    }
    cout<<ans.size()<<endl;
    if(ans.size()==0){ 
        cout<<endl; return;
    }
    for(auto i:ans) cout<<i<<" ";
    cout<<endl; return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}