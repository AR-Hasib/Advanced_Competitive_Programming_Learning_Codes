/* https://codeforces.com/problemset/problem/118/A

Petya started to attend programming lessons. On the first lesson his task was to write a simple program. 
The program was supposed to do the following: in the given string, consisting if uppercase and lowercase Latin letters, it:

    -deletes all the vowels,
    -inserts a character "." before each consonant,
    -replaces all uppercase consonants with corresponding lowercase ones.

Vowels are letters "A", "O", "Y", "E", "U", "I", and the rest are consonants. The program's input is exactly one string, 
it should return the output as a single string, resulting after the program's processing the initial string.

Help Petya cope with this easy task.

Input
The first line represents input string of Petya's program. This string only consists of uppercase and lowercase Latin letters and its length is from 1 to 100, inclusive.

Output
Print the resulting string. It is guaranteed that this string is not empty.*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    string s, ans; cin>>s;

    for(char c : s){
        if(c=='A' || c=='a' || c=='E' || c=='e' || c=='I' || c=='i' || c=='O' || c=='o' || c=='U' || c=='u' || c=='Y' || c=='y') continue;
        else if(c>='a'){
            ans.push_back('.');
            ans.push_back(c);
        }else{
            ans.push_back('.');
            ans.push_back(tolower(c));
        }
    }

    cout<<ans;

    return 0;
}