#include <bits/stdc++.h>
#define fo(i,m,n) for(int i = m; i <= n; i++)
#define fod(i,m,n) for(int i = m; i >= n; i--)
#define fov(i,x) for(auto &i : x)
using namespace std;

using i64 = int64_t;
using _ii = pair<int,int>;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	i64 n, m, k, x, ans = 0;
	cin >> n >> m >> k;

	vector<vector<i64>> a(n + 1, vector<i64>(m + 1));

	fo(i, 1, n)
	{
		fo(j, 1, m)
		{
			cin >> x;
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + x;
			if (i >= k && j >= k) {
				i64 sum = a[i][j] - a[i - k][j] - a[i][j - k] + a[i - k][j - k];
				ans = max(ans, sum);
			}
		}
	}

	cout << ans << '\n';
}