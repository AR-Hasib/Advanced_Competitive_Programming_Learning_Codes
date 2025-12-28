/*
https://codeforces.com/problemset/problem/1714/A

Vlad, like everyone else, loves to sleep very much.
Every day Vlad has to do n things, each at a certain time. For each of these things, he has an alarm clock set, the i-th of them is triggered
on 7₂ hours m₂ minutes every day (0 <h₂ < 24,0 ≤ mį < 60). Vlad uses the 24-hour time format, so after h = 12, m = 59 comes
h = 13, m = 0 and after h = 23, m = 59 comes h = 0, m = 0.
This time Vlad went to bed at H hours M minutes (0 ≤H <24,0 ≤ M < 60) and asks you to answer: how much he will be able to
sleep until the next alarm clock.
If any alarm clock rings at the time when he went to bed, then he will sleep for a period of time of length 0.

Input
The first line of input data contains an integer t (1 ≤ t ≤ 100) - the number of test cases in the test.
The first line of the case contains three integers n, H and M (1 ≤ n ≤ 10,0 ≤ H < 24,0 ≤ M < 60) — the number of alarms and
the time Vlad went to bed.
The following n lines contain two numbers each h; and m; (0 ≤ h; < 24,0 ≤ mį < 60) - the time of the i alarm. It is acceptable that
two or more alarms will trigger at the same time.
Numbers describing time do not contain leading zeros.

Output
Output t lines, each containing the answer to the corresponding test case. As an answer, output two numbers the number of hours and
minutes that Vlad will sleep, respectively. If any alarm clock rings at the time when he went to bed, the answer will be 0 0.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, h, m, a=0, aH, aM, alarm, sleep, diff;
    cin>>t;

    int arr[t];
    for(int i=0; i<t; i++){
        arr[i]=1440;
    }

    for(int a=0; a<t; a++){
        cin>>n>>h>>m;
        sleep= (h*60) + m;
        for(int i=0; i<n; i++){
            cin>>aH>>aM;
            alarm= (aH*60) + aM;
            diff= (alarm - sleep + 1440)%1440;
            if(arr[a]>diff) arr[a]=diff;
        }
    }

    for(int j=0; j<t; j++){
        cout<<arr[j]/60<<" "<<arr[j]%60<<endl;
    }

    return 0;
}