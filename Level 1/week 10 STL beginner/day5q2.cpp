/* https://www.codechef.com/LRNDSA02/problems/NOTALLFL

time 3s

Chef made N pieces of cakes, numbered them 1 through N and arranged them in a row in this order. 
There are K possible types of flavours (numbered 1 through K); for each valid ithe i-th piece of cake has a flavour A₁.
Chef wants to select a contiguous subsegment of the pieces of cake such that there is at least one flavour 
which does not occur in that subsegment. Find the maximum possible length ofsuch a subsegment of cakes.

Input
• The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
• The first line of each test case contains two integers N and K.
• The second line contains N space-separated integers A₁, A2, ……., AÑ.

Output
For each test case, print a single line containing one integer - the maximum length of a valid subsegment.

Constraints
• 1 ≤ T ≤ 1,000
• 1 ≤N ≤ 10^5
• 2 ≤K <10^5
• 1 ≤ A; ≤ K for each valid i
• the sum of N over all test cases does not exceed 10^6
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        unordered_map<int, int>mp;
        for(int i=1; i<=k; i++) mp[i]=-1;

        int ans=0;
        for(int i=0; i<n; i++){
            int x; cin>>x;
            ans= max(ans, i-mp[x]-1);
            mp[x]=i;
        }

        for(int i=1; i<=k; i++){
            ans= max(ans, n-mp[i]-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}