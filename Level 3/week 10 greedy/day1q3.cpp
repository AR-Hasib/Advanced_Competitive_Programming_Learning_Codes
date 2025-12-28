/* https://codeforces.com/contest/762/problem/B */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define int long long
#define ld long double
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define precision fixed<<setprecision

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int onlyUSB, onlyPS, both, m; cin>>onlyUSB>>onlyPS>>both>>m;

    vector<int>usb, ps;

    while(m--){
        int price; cin>>price;
        string type; cin>>type;
        if(type=="USB") usb.push_back(price);
        else ps.push_back(price);
    }

    sort(usb.begin(), usb.end());
    sort(ps.begin(), ps.end());

    int cost=0, equipped=0, a=0, b=0;
    for(int i=0; i<onlyUSB; i++){   // buying usb mouses and keep a point to calculate how many usb is left
        if(i<usb.size()){
            cost+=usb[i];
            equipped++;
            a++;
        }else break;
    }

    for(int i=0; i<onlyPS; i++){    // buying ps mouses and keep a point to calculate how many ps is left
        if(i<ps.size()){
            cost+=ps[i];
            equipped++;
            b++;
        }else break;
    }

    for(int i=0; i<both; i++){
        if(a<usb.size() && b<ps.size()){
            equipped++;
            if(usb[a]<ps[b]){
                cost+=usb[a];
                a++;
            }else{
                cost+=ps[b];
                b++;
            }
        }else if(a<usb.size()){
            equipped++;
            cost+=usb[a];
            a++;
        }else if(b<ps.size()){
            equipped++;
            cost+=ps[b];
            b++;
        }else break;
    }

    cout<<equipped<<" "<<cost<<endl;
    
    return 0;
}