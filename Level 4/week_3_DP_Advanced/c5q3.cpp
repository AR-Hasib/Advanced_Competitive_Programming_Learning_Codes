/* https://codeforces.com/problemset/problem/417/D */

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
//using namespace __gnu_pbds;
using namespace std;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define int long long

const int INF = 5e18;

struct person {
    int cost;
    int monitor;
    int mask;
    person() : cost(0), monitor(0), mask(0) {}
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, b; cin >> n >> m >> b;

    vector<person> arr(n);
    for (auto &p : arr) {
        cin >> p.cost >> p.monitor;
        int sz; cin >> sz;
        int tmpMask = 0;
        while (sz--) {
            int x; cin >> x; x--;  
            tmpMask |= (1LL << x);
        }
        p.mask = tmpMask;
    }

    sort(arr.begin(), arr.end(), [&](const person &l, const person &r){
        return l.monitor > r.monitor;
    });

    int fullMask = (1LL << m) - 1;
    int dpCur[1 << 20], dpNxt[1 << 20];

    for(int mask = 0; mask < (1 << m); mask++){
        dpNxt[mask] = (mask == fullMask ? 0 : INF);
    }

    vector<int> best(n, INF);

    for(int i = n - 1; i >= 0; i--){
        for(int mask = 0; mask < (1 << m); mask++){
            int costSkip = dpNxt[mask];
            int costTake = (arr[i].cost >= INF ? INF : arr[i].cost) + dpNxt[ mask | arr[i].mask ];
            dpCur[mask] = min(costSkip, costTake);
        }

        best[i] = dpCur[0];

        for(int mask = 0; mask < (1 << m); mask++){
            dpNxt[mask] = dpCur[mask];
        }
    }

    int answer = INF;
    for(int i = 0; i < n; i++){
        if (best[i] < INF) {
            answer = min(answer, best[i] + arr[i].monitor * b);
        }
    }

    if(answer >= INF) cout << -1 << endl;
    else cout << answer << endl;

    return 0;
}