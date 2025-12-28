/* https://leetcode.com/problems/subsets-ii/description/ */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void f(int idx, vector<int> &arr, vector<vector<int>>&ans, vector<int>curr){
    if(idx==arr.size()){
        bool flag=false;
        for(auto i:ans){
            if(i==curr){
                flag=true;
                break;
            }
        }
        if(!flag) ans.push_back(curr);
        return;
    }

    curr.push_back(arr[idx]);
    f(idx+1, arr, ans, curr);
    curr.pop_back();
    f(idx+1, arr, ans, curr);
}

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        vector<int>curr;
        f(0, nums, ans, curr);
        return ans;
    }
};

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    vector<int>input;
    while(n--){
        int temp; cin>>temp;
        input.push_back(temp);
    }

    Solution my;
    vector<vector<int>> a= my.subsetsWithDup(input);
    for(auto i:a){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
