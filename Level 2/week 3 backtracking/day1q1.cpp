/* https://leetcode.com/problems/combination-sum/description/ */

// leetcode
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void f(int idx, int target, vector<int>&arr, vector<int>&curr,vector<vector<int>>& ans){
    if(idx==arr.size()){
        if(target==0) ans.push_back(curr);
        return;
    }

    if(arr[idx]<=target){
        curr.push_back(arr[idx]);
        f(idx, target-arr[idx], arr, curr, ans);
        curr.pop_back();
    }
    f(idx+1, target, arr, curr, ans);
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
    vector<vector<int>> a= my.combinationSum(input, target);
    for(auto i:a){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
