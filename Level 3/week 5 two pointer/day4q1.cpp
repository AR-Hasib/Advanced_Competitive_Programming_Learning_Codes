/* https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/A */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

void solve(){
    int n, k; cin>>n>>k;
    vector<int>v(n);
    int sum=0;
    for(auto &i:v){
        cin>>i;
        sum+=i;
    }

    int start=1;
    int loop=2;
    if(k>sum){
        if(k%sum!=0) loop=(k/sum)+1;   // how many time i have to traverse the array
        else loop=k/sum;
    }

    int ans=INT_MAX;
    if(k<=sum){
        int i=0, j=0, curr=0;
        while(j<n*loop){
            while(j<n*loop){
                if(curr>=k) break;
                int idx=j%n;
                curr+=v[idx];
                j++;
            }

            int temp=ans;
            ans=min(ans, j-i);
            if(ans!=temp) start=(i%n)+1;

            int idx2=i%n;
            curr-=v[idx2];
            i++;
        }
    }else{
        if(k%sum==0) ans=(k/sum)*n; // no need to change start bcz it already 1;
        else{
            ans=(k/sum)*n;
            int needMore= k-(sum*(loop-1));
            int ext=INT_MAX;

            // cout<<"need"<<needMore<<" ";
            int i=0, j=0, curr=0;
            while(j<n*2){
                while(j<n*2){
                    if(curr>=needMore) break;
                    int idx=j%n;
                    curr+=v[idx];
                    j++;
                }

                int temp=ext;
                ext=min(ext, j-i);
                if(ext!=temp) start=(i%n)+1;

                int idx2=i%n;
                curr-=v[idx2];
                i++;
            }
            ans+=ext;
        }
    }
    cout<<start<<" "<<ans<<endl;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
        solve();
    
    return 0;
}