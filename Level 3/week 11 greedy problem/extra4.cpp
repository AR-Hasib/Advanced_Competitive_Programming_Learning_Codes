/* https://codeforces.com/problemset/problem/1157/C2 */

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
    int n; cin>>n;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    string ans = "";

    int left=0, right=n-1, curr=0;
    while(left<=right){
        if(v[left]>curr && v[right]>curr){  // both are greater than last taken element
            if(v[left]<v[right]){
                ans.push_back('L');
                curr = v[left];
                left++;
            }else if(v[right]<v[left]){
                ans.push_back('R');
                curr = v[right];
                right--;
            }else{  // both are equal
                break;
            }
        }else if(v[left]>curr){         // only left one is greater
            ans.push_back('L');
            curr = v[left];
            left++;
        }else if(v[right]>curr){        // only right one is greater
            ans.push_back('R');
            curr = v[right];
            right--;
        }else break;    // both are less than last taken element
    }

    if(v[left]==v[right] && v[left]>curr){
        if(left==right){    // we have one element left to be taken
            ans.push_back('R');
        }else{
            int lCount = 0, last=curr;
            for(int i=left; i<right; i++){
                if(v[i]>last){
                    lCount++;
                    last = v[i];
                }else break;
            }
            int rCount = 0; last=curr;
            for(int i=right; i>left; i--){
                if(v[i]>last){
                    rCount++;
                    last = v[i];
                }else break;
            }

            if(lCount>rCount){
                for(int i=left; i<right; i++){
                    if(v[i]>curr){
                        ans.push_back('L');
                        curr = v[i];
                    }else break;
                }
            }else{
                for(int i=right; i>left; i--){
                    if(v[i]>curr){
                        ans.push_back('R');
                        curr = v[i];
                    }else break;
                }
            }
        }
    }

    cout<<ans.size()<<endl<<ans<<endl;
    return;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc=1;
    while(tc--){
        solve();
    }
    return 0;
}