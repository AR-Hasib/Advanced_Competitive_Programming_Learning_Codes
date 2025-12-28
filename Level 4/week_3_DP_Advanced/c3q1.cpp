/* count the number of numbers from 0 to num=10^18 whose sum of the digit is SUM=150 */

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
#define toLDouble static_cast<long double>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

string num = "1000000000000000000"; // max number
const int N=20, maxSum=200; // assuming for declaring the vector
vector<vector<vector<int>>> dp(N, vector<vector<int>>(2, vector<int>(maxSum, -1)));
int SUM=150; // our target sum

int f(int index, int tight, int sumMadeYet){
    if(sumMadeYet > SUM) return 0;
    if(index == sz(num)){
        if(sumMadeYet == SUM) return 1;
        return 0;
    }

    if(dp[index][tight][sumMadeYet] != -1) return dp[index][tight][sumMadeYet];

    int sum = 0;
    int bound = (tight == 1 ? num[index]-'0' : 9);
    for(int i=0; i<=bound; i++){
        sum += f(index+1, ((tight==1) && (i == num[index]-'0')) ? 1:0, sumMadeYet+i);
    }

    return dp[index][tight][sumMadeYet] = sum;
}


signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cout<<f(0, 1, 0);
    
    return 0;
}