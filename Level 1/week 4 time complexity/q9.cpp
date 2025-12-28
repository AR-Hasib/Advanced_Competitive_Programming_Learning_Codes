/* https://codeforces.com/problemset/problem/1614/B

The company "Divan's Sofas" is planning to build n + 1 different buildings on a coordinate line so that:
• the coordinate of each building is an integer number;
• no two buildings stand at the same point.
Let , be the coordinate of the i-th building. To get from the building to the building j, Divan spends |x₁ - x; minutes, where lyl is the
absolute value of y.
All buildings that Divan is going to build can be numbered from 0 to n. The businessman will live in the building 0, the new headquarters of
"Divan's Sofas". In the first ten years after construction Divan will visit the i-th building a times, each time spending 2 - 0 - ₂ minutes
for walking.
Divan asks you to choose the coordinates for all n +1 buildings so that over the next ten years the businessman will spend as little time
for walking as possible.
Input
Each test contains several test cases. The first line contains one integer numbert (1 < t ≤ 10³) — the number of test cases.
The first line of each case contains an integer n (1 ≤ n ≤2·105) - the number of buildings that "Divan's Sofas" is going to build, apart
from the headquarters.
The second line contains the sequence a₁, a2, ..., an (0 ≤ ai ≤ 10%), where a; is the number of visits to the i-th building.
It is guaranteed that the sum of n over all test cases does not exceed 2.105.
Output
For each test case, on the first line print the number T - the minimum time Divan will spend walking.
On the second line print the sequence , £₁,..., n of n + 1 integers, where ; (−10⁰ ≤ xį ≤ 10º) is the selected coordinate of the
¿-th building. It can be shown that an optimal answer exists with coordinates not exceeding 10⁰.
If there are multiple answers, print any of them.  */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        int n; cin>>n;
        vector<pair<int, int>>v;
        for(int i=0; i<n; i++){
            int a; cin>>a;
            v.push_back({a, i});
        }

        int time=0, curr=1;
        int ans[n];
        sort(v.begin(), v.end());
        for(int i=n-1; i>=0; i--){
            ans[v[i].second] = curr;
            time+= (2*(v[i].first*abs(curr))); 
            curr*= -1;
            if(curr>0) curr++;
        }
        cout<<time<<endl;
        cout<<"0 ";
        for(int i=0; i<n; i++) cout<<ans[i]<<" ";
    }
    return 0;
}