/* https://www.codechef.com/LRNDSA03/problems/CVOTE

Chefs from all over the globe gather each year for an international convention. Each chef represents some country. 
Please, note that more than one chef can represent a country.

Each of them presents their best dish to the audience. The audience then sends emails to a secret and secure mail server, 
with the subject being the name of the chef whom they wish to elect as the "Chef of the Year".

You will be given the list of the subjects of all the emails. Find the country whose chefs got the most number of votes, 
and also the chef who got elected as the "Chef of the Year" (the chef who got the most number of votes).

Note 1
If several countries got the maximal number of votes, consider the country with the lexicographically smaller name among 
them to be a winner. Similarly if several chefs got the maximal number of votes, consider the chef with the lexicographically 
smaller name among them to be a winner.

Note 2
The string A = a1a2...an is called lexicographically smaller then the string B = b1b2...bm in the following two cases:

there exists index i ≤ min{n, m} such that aj = bj for 1 ≤ j < i and ai < bi;
A is a proper prefix of B, that is, n < m and aj = bj for 1 ≤ j ≤ n.
The characters in strings are compared by their ASCII codes.

Refer to function strcmp in C or to standard comparator < for string data structure in C++ for details.

Input
The first line of the input contains two space-separated integers N and M denoting the number of chefs and the number 
of emails respectively. Each of the following N lines contains two space-separated strings, denoting the name of the 
chef and his country respectively. Each of the following M lines contains one string denoting the subject of the email.

Output
Output should consist of two lines. The first line should contain the name of the country whose chefs got the most number 
of votes. The second line should contain the name of the chef who is elected as the "Chef of the Year".

Constraints
1 ≤ N ≤ 10000 (104)
1 ≤ M ≤ 100000 (105)
Each string in the input contains only letters of English alphabets (uppercase or lowercase)
Each string in the input has length not exceeding 10
All chef names will be distinct
Subject of each email will coincide with the name of one of the chefs
*/

////this solution is ok but time limit exceed
// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define int long long

// const int MOD = 1e9 + 7;
// const int INF = LLONG_MAX /2;

// signed main() {
    
//     ios::sync_with_stdio(false); cin.tie(NULL);
    
//     int n, m; cin>>n>>m;
//     vector<pair<string, string>>v(n);
//     for(int i=0; i<n; i++){
//         string s, t; cin>>s>>t;
//         v[i].first=s;
//         v[i].second=t;
//     }
//     vector<pair<string, string>>mail(m);
//     for(int i=0; i<m; i++){
//         string s; cin>>s;
//         mail[i].first=s;
//         for(int j=0; j<n; j++){
//             if(v[j].first==s){
//                 mail[i].second=v[j].second;
//                 break;
//             }
//         }
//     }

//     //most voted food
//     sort(mail.begin(), mail.begin()+m);
//     int count=0, cc=1;
//     string food, cs=mail[0].first;
//     for(int i=1; i<m; i++){
//         if(mail[i].first==cs){
//             cc++;
//             if(cc>count){
//                food=cs;
//                count=cc; 
//             }
//         }else{
//             cc=1;
//             cs=mail[i].first;
//         }
//     }

//     //most voted country
//     set<string>st;
//     for(int i=0; i<n; i++){
//         st.insert(v[i].second);
//     }
//     int totalCountry= st.size();
//     vector<string>vec(totalCountry);
//     int arr[totalCountry];
//     int x=0; 
//     for(int i=0; i<m; i++){
//         bool flag= false;
//         for(int j=0; j<x; j++){
//             if(mail[i].second==vec[j]){
//                 flag= true;
//                 break;
//             }
//         }
//         if(!flag){
//             vec[x]=mail[i].second;
//             x++;
//         }
//     }
//     sort(vec.begin(), vec.begin()+totalCountry);

//     for(int i=0; i<totalCountry; i++) arr[i]=0;
//     for(int i=0; i<m; i++){
//         for(int j=0; j<totalCountry; j++){
//             if(mail[i].second==vec[j]) arr[j]++;
//         }
//     }
//     int big=0, index=0;
//     for(int i=0; i<totalCountry; i++){
//         if(arr[i]>big){
//             big=arr[i];
//             index=i;
//         } 
//     }
//     cout<<vec[index]<<endl<<food;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin>>n>>m;
    map<string, string>mp;
    for(int i=0; i<n; i++){
        string a, b; cin>>a>>b;
        mp[a]=b;
    }

    map<string, int>country, food;
    for(int i=0; i<m; i++){
        string mail; cin>>mail;
        food[mail]++;
        country[mp[mail]]++;
    }

    int mxfood=0, mxc=0;
    for(auto it : food) mxfood= max(mxfood, it.second);
    for(auto it : country) mxc= max(mxc, it.second);
    
    for(auto it : country){
        if(mxc==it.second){
            cout<<it.first<<endl;
            break;
        }
    }
    for(auto it : food){
        if(mxfood==it.second){
            cout<<it.first<<endl;
            break;
        }
    }
    
    return 0;
}