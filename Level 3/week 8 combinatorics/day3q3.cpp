/* https://codeforces.com/problemset/problem/1284/C */

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

void calculate_factorial(vector<int> &fact, int n, int M){
    for(int i=2; i<=n; i++) fact[i] = (fact[i-1]*i)%M;
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, MOD; cin>>n>>MOD;
    vector<int> fact(n+1, 1);
    calculate_factorial(fact, n, MOD);

    /* D = difference r-l
        when n=3; let we have n boxes
            for every possible difference at first we select how many ways we can select l and r so that 
            the difference is equal to D. then we have to place them into boxes and calculate all the possible ways for all D

            the formula is:
                        ways to choose the numbers * combinations among them * combinations among the rests * ways to choose the box where we can place the choosen numbers
            for D=0     3 * 1! * 2! * 3
            for D=1     2 * 2! * 1! * 2
            for D=2     1 * 3! * 0! * 1

        here we can see a pattern
    */

    int final_ans=0;
    for(int i=n, j=1; i>0, j<=n; i--, j++){
        int ans=1;
        ans = (ans*i)%MOD;
        ans = (ans*fact[j])%MOD;
        ans = (ans*fact[i-1])%MOD;
        ans = (ans*i)%MOD;
        final_ans = (final_ans+ans)%MOD;
    }
    cout<<final_ans<<endl;

    return 0;
}