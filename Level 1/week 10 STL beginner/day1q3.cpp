/* https://codeforces.com/problemset/problem/637/B

time 3s

Polycarp is a big lover of killing time in social networks. A page with a chatlist in his favourite network is made so 
that when a message is sent to some friend, his friend's chat rises to the very top of the page. The relative order of 
the other chats doesn't change. If there was no chat with this friend before, then a new chat is simply inserted to the top of the list.

Assuming that the chat list is initially empty, given the sequence of Polycaprus' messages make a list of chats after 
all of his messages are processed. Assume that no friend wrote any message to Polycarpus.

Input
The first line contains integer n (1 ≤ n ≤ 200 000) — the number of Polycarpus' messages. Next n lines enlist the message recipients in the order in which the messages were sent. The name of each participant is a non-empty sequence of lowercase English letters of length at most 10.

Output
Print all the recipients to who Polycarp talked to in the order of chats with them, from top to bottom.
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX /2;

signed main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin>>n;
    set<string>chat;
    stack<string>message;
    while(n--){
        string s; cin>>s;
        message.push(s);
    }

    while(!message.empty()){
        string b=message.top();
        if(chat.find(b) == chat.end()){ // chat.find(b) -> if b is present in the set, it will point to the address of the element b. if not it will point to the address of chat.end() [an adress after the set]
            cout<<b<<endl;
            chat.insert(b);
        }
        message.pop();
    }

    return 0;
}