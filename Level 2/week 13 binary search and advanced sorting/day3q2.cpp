/* https://codeforces.com/gym/101853/problem/C */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int merge(int left, int right, int mid, vector<int> &arr){
    vector<int>temp;
    // [left.......mid]
    // [mid+1......right]
    int ans=0;
    int lStart=left, rStart=mid+1;
    while(lStart<=mid && rStart<=right){
        if(arr[lStart]<=arr[rStart]){              // merging with ascending order
            temp.push_back(arr[lStart]);
            lStart++;
        }else{
            ans+=(mid-lStart+1);
            temp.push_back(arr[rStart]);
            rStart++;
        }
    }
    while(lStart<=mid){                           // adding if some elements left     
        temp.push_back(arr[lStart]);
        lStart++;
    }
    while(rStart<=right){                          
        temp.push_back(arr[rStart]);
        rStart++;
    }
    for(int i=left; i<=right; i++) arr[i]=temp[i-left];         // replacing with original vector
    return ans;
}

int mergeSort(int left, int right, vector<int> &arr){
    if(left>=right) return 0;

    int mid=(left+right)/2;
    int ans=0;
    ans+=mergeSort(left, mid, arr);              // split left part
    ans+=mergeSort(mid+1, right, arr);           // split right part
    ans+=merge(left, right, mid, arr);
    return ans;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];
        
        map<int, int> mp;
        for(int i=0; i<n; i++) mp[a[i]]=i;

        vector<int> arr(n);
        for(int i=0; i<n; i++) arr[i]=mp[b[i]];

        int ans= mergeSort(0, n-1, arr);
        cout<<ans<<endl;
    }

    return 0;
}