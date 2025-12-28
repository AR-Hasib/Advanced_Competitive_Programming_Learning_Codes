// /* https://codeforces.com/contest/711/problem/C */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(x) ((int)(x).size())

const int INF = 5e18;

int f(int index, int beauty, int lastCol, int n, int m, int k, vector<int>& c, vector<vector<int>>& p, vector<vector<vector<int>>>& dp) {
    
    if (beauty > k) return INF;
    if (index == n) return (beauty == k) ? 0 : INF;

    if (dp[index][beauty][lastCol + 1] != -1) return dp[index][beauty][lastCol + 1];

    int ans = INF;

    if (c[index] != 0) {
        int newBeauty = beauty + (c[index] != lastCol);
        ans = f(index + 1, newBeauty, c[index], n, m, k, c, p, dp);
    } else {
        for (int newCol = 1; newCol <= m; ++newCol) {
            int newBeauty = beauty + (newCol != lastCol);
            int cost = p[index][newCol - 1];
            ans = min(ans, cost + f(index + 1, newBeauty, newCol, n, m, k, c, p, dp));
        }
    }

    return dp[index][beauty][lastCol + 1] = ans;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> c(n);
    for (auto& i : c) cin >> i;

    vector<vector<int>> p(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> p[i][j];

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(m + 2, -1)));

    int result = f(0, 0, -1, n, m, k, c, p, dp);

    if (result >= INF) cout << -1 << endl;
    else cout << result << endl;

    return 0;
}
