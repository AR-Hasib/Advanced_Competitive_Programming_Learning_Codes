/* https://www.codechef.com/LRNDSA03/problems/SAVKONO

Pain is the leader of a secret organization whose goal is to destroy the leaf village(Konoha). After successive 
failures, the leader has himself appeared for the job. Naruto is the head of the village but he is not in a
condition to fight so the future of the village depends on the soldiers who have sworn to obey Naruto till death.
Naruto is a strong leader who loves his villagers more than anything but tactics is not his strong area. He is 
confused whether they should confront Pain or evacuate the villagers including the soldiers (he loves his
villagers more than the village). Since you are his advisor and most trusted friend, Naruto wants you to take the decision.
Pain has a strength of Z and is confident that he will succeed. Naruto has N soldiers under his command numbered 1 through N. 
Power of ith soldier is denoted by A₁. When a soldier attacks pain, his strength gets
reduced by the corresponding power of the soldier. However, every action has a reaction so the power of the soldier also gets 
halved i.e. A¿ changes to [A₁/2]. Each soldier may attack any number of times (including 0).
Pain is defeated if his strength is reduced to 0 or less.
Find the minimum number of times the soldiers need to attack so that the village is saved.

Input Format
• First line will contain T, number of test cases. Then the test cases follow.
• The first line of each test case contains two space-separated integers N and Z.
• The second line contains N space-separated integers A₁, A2, ..., Ay the attacking power of the soldiers.

Output Format
For each test case, print a single line. If Pain cannot be defeated, this line should contain the string "Evacuate" (without quotes). Otherwise, it should contain the minimum number of times the soldiers need to attack.

Constraints
• 1 ≤ T ≤ 10
• 1<N<10^5
• 1 <Z < 10^8
• 1 ≤ A; ≤ 10^4
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
        int n, z; cin>>n>>z;
        priority_queue<int>pq;
        while(n--){
            int temp; cin>>temp;
            pq.push(temp);
        }

        int count=0;
        while(z>0 && pq.top()>0){
            int a= pq.top();
            z-=a;
            pq.pop();
            a/=2;
            pq.push(a);
            count++;
        }
        if(z>0) cout<<"Evacuate"<<endl;
        else cout<<count<<endl;
    }
    return 0;
}