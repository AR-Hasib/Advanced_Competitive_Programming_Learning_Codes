/* https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description/ */

#include <bits/stdc++.h>
using namespace std;

int minimumObstacles(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, 1, -1};
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({grid[0][0], {0, 0}});
    dist[0][0] = grid[0][0];
    while(!pq.empty()){
        int currDist = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(currDist > dist[x][y]) continue;
        for(int i=0; i<4; i++){
            int newX = x+dx[i];
            int newY = y+dy[i];
            if(newX>=0 && newY>=0 && newX<n && newY<m){
                int newDist = currDist+grid[newX][newY];

                if(newDist < dist[newX][newY]){
                    dist[newX][newY] = newDist;
                    pq.push({newDist, {newX, newY}});
                }
            }
        }
    }
    return dist[n-1][m-1];
}
