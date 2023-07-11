#include <bits/stdc++.h>

using namespace std;

long n, m, k, x, res = 0;
vector <vector <long>> a;

int main()
{
	cin >> n >> m >> k;
	a.resize(n+1);
	for(auto &i : a) i.resize(m+1);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> x;
			a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + x;
			if(i - k >= 0 && j - k >= 0) res = max(res,a[i][j] - a[i-k][j] - a[i][j-k] + a[i-k][j-k]);
		}
	}
	cout << res;
    return 0;
}