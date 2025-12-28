/* https://leetcode.com/problems/combination-sum-ii/description/ */

// leetcode
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
    void f(int idx, int target, vector<int>&arr, vector<int>&curr, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(curr);
            return;
        }

        for(int i=idx; i<arr.size(); i++){
            if(i>idx && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            curr.push_back(arr[i]);
            f(i+1, target-arr[i], arr, curr, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>curr;
        f(0, target, candidates, curr, ans);
        return ans;
    }
};

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, target; cin>>n>>target;
    vector<int>input;
    while(n--){
        int temp; cin>>temp;
        input.push_back(temp);
    }

    Solution my;
    vector<vector<int>> a= my.combinationSum2(input, target);
    for(auto i:a){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
