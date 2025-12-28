/*https://leetcode.com/problems/validate-stack-sequences/description/ */

// solution 1
// bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//     stack<int>st;
//     st.push(-1);
//     int n=pushed.size();
//     int i=0, j=0;

//     while(i<n && j<n){
//         int y=popped[j], x=pushed[i];
//         if(y==x){
//             j++;
//             i++;
//         }
//         else if(y==st.top()){
//             st.pop();
//             j++;
//         }
//         else{
//             st.push(x);
//             i++;
//         } 
//     }

    
//     while(j<n && popped[j]==st.top()){
//         st.pop();
//         j++;
//     }

//     if(st.top()==-1) return true;
//     else return false;
// }


// solution 2 -- better approach
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n= pushed.size();
        stack<int>st;
        int i=0, j=0;

        while(i<n && j<n){
            st.push(pushed[i]);
            while(!st.empty() && st.top()==popped[j]){
                st.pop();
            }
            i++;
        }

        if(st.empty()) return true;
        else return false;
    }
};