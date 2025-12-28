/* https://leetcode.com/problems/generate-parentheses/description/ */
// leetcode

// class Solution {
// public:
//     void solve(vector<string>&ans, int idx, int n, int open, string curr){
//         if(idx==2*n){
//             if(open==0) ans.push_back(curr);
//             return;
//         }

//         solve(ans, idx+1, n, open+1, curr+"(");
//         if(open) solve(ans, idx+1, n, open-1, curr+")");
//     }

//     vector<string> generateParenthesis(int n) {
//         vector<string>ans;
//         solve(ans, 0, n, 0, "");
//         return ans;
//     }
// };