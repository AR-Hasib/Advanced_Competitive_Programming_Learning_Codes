/* https://leetcode.com/problems/subsets/description/ */

// did the code in leetcode

// class Solution {
// public:
//     vector<vector<int>> final;
//     vector<int> val;
//     vector<int>curr;

//     void solve(int i){
//         if(i==val.size()){
//             final.push_back(curr);
//             return;
//         }

//         solve(i+1);
//         curr.push_back(val[i]);
//         solve(i+1);
//         curr.pop_back();
//     }


//     vector<vector<int>> subsets(vector<int>& nums) {
//         final.clear();
//         val=nums;
//         solve(0);
//         return final;
//     }
// };