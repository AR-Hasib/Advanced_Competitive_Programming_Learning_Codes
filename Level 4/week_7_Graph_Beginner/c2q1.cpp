/* https://leetcode.com/problems/rotting-oranges/description/ */

#include <bits/stdc++.h>
using namespace std;



int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int rotten = 0, leftToRotten = 0;
    // 0->empty, 1->fresh, 2->rotten
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1) leftToRotten++;
            else if(grid[i][j] == 2) rotten++;
        }
    }

    // no rotten is there
    if(leftToRotten > 0 && rotten == 0) return -1;
    // all rotten
    if(leftToRotten == 0) return 0;

    // some is rotten and some is fresh
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, 1, -1};
    queue<pair<int, int>> q;
    int minutes = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 2) q.push({i, j});
        }
    }

    while(!q.empty()){
        if(leftToRotten == 0) break;

        minutes++;
        int currLevelElements = q.size();
        for(int i=0; i<currLevelElements; i++){
            auto curr = q.front(); q.pop();

            for(int j=0; j<4; j++){
                pair<int, int> next = {curr.first+dx[j], curr.second+dy[j]};

                // ensure this is in the range and fresh
                if(next.first>=0 && next.first<n && next.second>=0 && next.second<m && grid[next.first][next.second]==1){
                    grid[next.first][next.second] = 2;
                    leftToRotten--;
                    q.push(next);
                }
            }
        }
    }
    
    if(leftToRotten == 0) return minutes;
    else return -1;
}
