/* https://codeforces.com/contest/1551/problem/B1

Paul and Mary have a favorite string s
 which consists of lowercase letters of the Latin alphabet. They want to paint it using pieces of chalk of 
 two colors: red and green. Let's call a coloring of a string wonderful if the following conditions are met:

each letter of the string is either painted in exactly one color (red or green) or isn't painted;
each two letters which are painted in the same color are different;
the number of letters painted in red is equal to the number of letters painted in green;
the number of painted letters of this coloring is maximum among all colorings of the string which meet the first three conditions.
E. g. consider a string s
 equal to "kzaaa". One of the wonderful colorings of the string is shown in the figure.

The example of a wonderful coloring of the string "kzaaa".
Paul and Mary want to learn by themselves how to find a wonderful coloring of the string. But they are very young, so they need a hint. Help them find k
 — the number of red (or green, these numbers are equal) letters in a wonderful coloring.

Input
The first line contains one integer t (1≤t≤1000) — the number of test cases. Then t test cases follow.

Each test case consists of one non-empty string s which consists of lowercase letters of the Latin alphabet. 
The number of characters in the string doesn't exceed 50.

Output
For each test case, output a separate line containing one non-negative integer k — the number of 
letters which will be painted in red in a wonderful coloring.*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        string s; cin>>s;
        vector<int> v(123, 0);
        int i=0;
        while(s[i]!='\0'){
            v[int(s[i])]++;
            i++;
        }
        int sum=0;
        for(int i=97; i<123; i++){
            if(v[i]==1) sum++;
            else if(v[i]>1) sum+=2;
        }
        cout<<sum/2<<endl;
    }
    return 0;
}