/* https://www.codechef.com/LRNDSA03/problems/FENCE

There is a field with plants - a grid with N rows (numbered 1 through N) and M columns (numbered 1 through M); 
out of its NM cells, K cells contain plants, while the rest contain weeds. Two cells are adjacent if
they have a common side.
You want to build fences in the field in such a way that the following conditions hold for each cell that contains a plant:
• it is possible to move from this cell to each adjacent cell containing a plant without crossing any fences
it is impossible to move from this cell to any cell containing weeds or to leave the grid without crossing any fences
The fences can only be built between cells or on the boundary of the grid, i.e. on the sides of cells. The total 
length of the built fences is the number of pairs of side-adjacent cells such that there is a fence built on their
common side plus the number of sides of cells on the boundary of the grid which have fences built on them. Find the 
minimum required total length of fences that need to be built.

Input
• The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
• The first line of each test case contains three space-separated integers N. M and K.
• K lines follow. Each of these lines contains two space-separated integers rand c denoting that the cell in row r and column c contains a plant.

Output
For each test case, print a single line containing one integer - the minimum required length of fences.

Constraints
• 1 ≤ T ≤ 10
• 1<N, M≤ 10⁹
• 1< K≤ 10^5
• 1<r<N
• 1<c<M
• the cells containing plants are pairwise distinct
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
        int n, m, k; cin>>n>>m>>k;
        set<pair<int, int>>plant;
        while(k--){
            int a, b; cin>>a>>b;
            plant.insert({a, b});
        }

        int fench= plant.size() * 4;
        for(auto [a, b] : plant){
            if(plant.count({a-1, b})) fench--;
            if(plant.count({a+1, b})) fench--;
            if(plant.count({a, b-1})) fench--;
            if(plant.count({a, b+1})) fench--;  
        }
        cout<<fench<<endl;
    }
    return 0;
}