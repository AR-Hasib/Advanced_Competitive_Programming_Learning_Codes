/* https://codeforces.com/problemset/problem/1359/C */

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long int
#define double long double
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

void solve(){
    double h, c, t;
	cin >> h >> c >> t;
	double diff = abs(h - t);
	ll ans = 1;
	if (abs((h + c) / 2 - t ) < diff)
	{
		ans = 2;
		diff = abs((h + c) / 2  - t);
	}
	if (2 * t != h + c)
	{
		double k = (t - c) / (2 * t - h - c);
		double x1 = ceil(k);
		double x2 = floor(k);
 
		if (x2 > 1)
		{
			double val = abs((x2 * h + (x2 - 1) * c) / (2 * x2 - 1) - t);
			if (val < diff)
			{
				ans = 2 * x2 - 1;
				diff = val;
			}
		}
		if (x1 > 1)
		{
			double val = abs((x1 * h + (x1 - 1) * c) / (2 * x1 - 1) - t);
			if (val < diff)
			{
				ans = 2 * x1 - 1;
				diff = val;
			}
		}
	}
	cout << ans << '\n';
}

signed main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}