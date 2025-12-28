/* https://codeforces.com/problemset/problem/1799/C */

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
    string s; cin>>s;
    sort(s.begin(), s.end());
    int n = s.size();

    vector<char> v(n);
    int left=0, right=n-1;
    for(int i=0; i<n; i+=2){
        if(i==n-1) v[left]=s[i];
        else if(s[i]==s[i+1]){
            v[left]=s[i];
            v[right]=s[i+1];
            left++;
            right--;
        }else{
            if(s[i+1]==s[n-1]){
                char temp=s[i];
                i++;
                while(left<=right){
                    if(left==right) v[left]=temp;
                    else if(left+1 == right){
                        v[left] = s[i];
                        v[right]= temp;
                    }else{
                        v[left] = s[i];
                        i++;
                        v[right]= s[i];
                    }
                    i++;
                    left++;
                    right--;
                }
                
            }else{
                v[right]=s[i];
                i++;
                while(left<right){
                    v[left]=s[i];
                    i++;
                    left++;
                }
            }
            break;
        }
    }

    string ans ="";
    for(auto i:v) ans.push_back(i);
    cout<<ans<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}