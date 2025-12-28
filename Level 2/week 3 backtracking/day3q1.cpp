/* https://leetcode.com/problems/n-queens/description/ */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

class Solution {
public:
    bool check(int row, int col, int n, vector<string>&board){
        int dupRow=row;
        int dupCol=col;

        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }

        row=dupRow; col=dupCol;
        while(col>=0 && row<n){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }

        row=dupRow; col=dupCol;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        
        return true;
    }

    void solve(int col, vector<vector<string>>&ans, vector<string>&board, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(check(row, col, n, board)){
                board[row][col]='Q';
                solve(col+1, ans, board, n);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n, string(n, '.'));
        solve(0, ans, board, n);

        return ans;
    }
};

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    Solution my;
    vector<vector<string>> a= my.solveNQueens(n);
    for(auto i:a){
        for(auto j:i) cout<<j<<endl;
        cout<<endl;
    }
    
    return 0;
}