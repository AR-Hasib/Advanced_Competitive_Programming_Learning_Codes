//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ll long long
#define ld long double
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define precision fixed<<setprecision

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX /2;

void solve(){
    string s, t; int k; cin>>s>>k;
    deque<int> nums[10];

    // store the indices of every number
    for(int i=0; i<s.size(); i++) nums[s[i]-'0'].push_back(i);

    for(int i=0; i<s.size(); i++){
        int currIdx = s.size(), newIdx = s.size();

        // first index which is present
        for(int j=0; j<10; j++){
            if(nums[j].size()) currIdx = min(currIdx, nums[j].front());
        }

        // finding the smallest number that can be select for msb(most significant bit)
        for(int j=(i==0); j<10; j++){
            if(nums[j].size() && nums[j].front()-currIdx <= k){
                t+=('0'+j);
                newIdx = nums[j].front();
                break;
            }
        }

        k -= newIdx-currIdx; // how much element i have to delete

        // deleting the elements 
        for(int j=0; j<10; j++){
            while(nums[j].size() && nums[j].front() <= newIdx) nums[j].pop_front();
        }
    }

    cout<< string(t.begin(), t.end()-k)<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}