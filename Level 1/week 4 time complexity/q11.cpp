/* https://codeforces.com/problemset/problem/1509/B

The student council has a shared document file. Every day, some members of the student council write the sequence TMT (short for Towa Maji Tenshi) in it.

However, one day, the members somehow entered the sequence into the document at the same time, creating a jumbled mess.
Therefore, it is Suguru Doujima's task to figure out whether the document has malfunctioned. Specifically, he is given a
string of length n whose characters are all either T or M, and he wants to figure out if it is possible to partition it
into some number of disjoint subsequences, all of which are equal to TMT. That is, each character of the string should 
belong to exactly one of the subsequences.

A string a is a subsequence of a string b if a can be obtained from b by deletion of several (possibly, zero) characters.

Input
The first line contains an integer t(1≤t≤5000)  — the number of test cases.

The first line of each test case contains an integer n (3≤n<10^5), the number of characters in the string entered in the document.
It is guaranteed that n is divisible by 3.

The second line of each test case contains a string of length n consisting of only the characters T and M.

It is guaranteed that the sum of n over all test cases does not exceed 10^5.

Output
For each test case, print a single line containing YES if the described partition exists, and a single line containing NO otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        int n; cin>>n;
        string s; cin>>s;

        int cntT=0, cntM=0;
        for(int i=0; i<n; i++){
            if(s[i]=='T') cntT++;
            else cntM++;
        }
        if(cntT == (2*cntM)){
            cntT=0; cntM=0;
            bool flag= true;
            for(int i=0; i<n; i++){
                if(s[i]=='T') cntT++;
                else cntM++;
                if(cntM>cntT){
                    flag= false;
                    break;
                }
            }
            if(flag == true){
                cntM=0; cntT=0;
                for(int i=n-1; i>=0; i--){
                    if(s[i]=='T') cntT++;
                    else cntM++;
                    if(cntM>cntT){
                        flag= false;
                        break;
                    }
                }
            }
            if(flag == true) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else cout<<"NO"<<endl;
    }
    return 0;
}