/* https://codeforces.com/problemset/problem/1223/C */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

bool possible(vector<int>& ticket, int x, int a, int y, int b, int mid, int total){
    int money=0;
    if(a==b){
        x+=y;
        int temp= mid/a; // number of ticket that will contribute
        money= ticket[temp]*x; // ticket*a% * 100(as we reduce before)
    }else{
        if(x>y){
            int lc= (a*b) / __gcd(a, b);
            int common= mid/lc; // common element
            int temp1= (mid/a)-common; // will contribute more
            int temp2= (mid/b)-common; // will contribute less

            money+= ticket[common]*(x+y);
            money+= (ticket[temp1+common]-ticket[common])*x;
            money+= (ticket[temp2+temp1+common]-ticket[common+temp1])*y;
        }
        else{
            int lc= (a*b) / __gcd(a, b);
            int common= mid/lc; // common element
            int temp1= (mid/b)-common; // will contribute more
            int temp2= (mid/a)-common; // will contribute less

            money+= ticket[common]*(x+y);
            money+= (ticket[temp1+common]-ticket[common])*y;
            money+= (ticket[temp2+temp1+common]-ticket[common+temp1])*x;
        }
    }
    return money>=total;
}

void solve(){
    int n; cin>>n;
    vector<int>ticket(n+1, 0);
    for(int i=1; i<=n; i++){
         cin>>ticket[i];
         ticket[i]=ticket[i]/100;
    }

    int x, a, y, b, total; cin>>x>>a>>y>>b>>total;

    sort(ticket.begin()+1, ticket.end(), greater<int>());
    for(int i=1; i<=n; i++) ticket[i]+=ticket[i-1];

    int left=1, right=n, ans=-1;
    while(left<=right){
        int mid=(left+right)/2;

        if(possible(ticket, x, a, y, b, mid, total)){
            ans=mid;
            right=mid-1;
        }else left=mid+1;
    }
    cout<<ans<<endl;

}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}