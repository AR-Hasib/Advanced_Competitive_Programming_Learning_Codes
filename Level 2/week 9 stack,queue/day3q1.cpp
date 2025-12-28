/* https://leetcode.com/problems/kth-largest-element-in-a-stream/description/ */

// solution 1
// class KthLargest {
// public:
//     priority_queue<int, vector<int>, greater<int>>pq;
//     KthLargest(int k, vector<int>& nums) {
//         int n= nums.size();
//         int i=0, j=0;
//         while(j<k && i<n){
//             pq.push(nums[i]);
//             i++;
//             j++;
//         }
//         while(i<n){
//             if(!pq.empty() && pq.top()<nums[i]){
//                 pq.pop();
//                 pq.push(nums[i]);
//             }
//             if(pq.empty()){
//                 pq.push(nums[i]);
//             }
//             i++;
//         }
//     }
    
//     int add(int val) {
//         if(!pq.empty() && pq.top()<val){
//             pq.pop();
//             pq.push(val);
//         }
//         if(pq.empty()){
//             pq.push(val);
//         }
//         return pq.top();
//     }
// };



//solution 2
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        kth=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>kth) pq.pop();
        return pq.top();
    }
};