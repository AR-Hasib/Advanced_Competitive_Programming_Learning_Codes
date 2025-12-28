/* https://atcoder.jp/contests/abc241/tasks/abc241_b

There is pasta consisting of N noodles at Takahashi's home. The length of the i-th noodle is A i.
Takahashi has a meal plan for the next M days. On the i-th day, he is going to choose a pasta noodle of length exactly Bi
​and eat it. If no such noodle is available on any day, his plan fails. Additionally, he cannot eat the same noodle on multiple days.

Can Takahashi accomplish his meal plan?

Constraints
1≤M≤N≤1000
1≤Ai≤10^9 
1≤Bi≤10^9
 
All values in input are integers.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
   int n, m; cin>>n>>m;
   int nod[n], meal[m];
   for(int i=0; i<n; i++) cin>>nod[i];
   for(int i=0; i<m; i++) cin>>meal[i];

    sort(nod, nod+n);
    sort(meal, meal+m);

    int i=0, j=0, count=0;
    while(i<n){
        if(meal[j]==nod[i]){
            count++;
            j++;
            i++;
        }else if(meal[j]>nod[i]) i++;
        else if(meal[j]<nod[i]) break;
    }
    if(count==m) cout<<"Yes";
    else cout<<"No";

    return 0;
}