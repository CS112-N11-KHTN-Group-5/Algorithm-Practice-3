#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, n, k;
	cin>>n>>m>>k;
	vector<vector<long long> > a;
	a.resize(n+1,vector<long long>(m+1,0));
	for (int i = 1; i<=n; ++i)
		for (int j = 1; j<=m; ++j)
		{
			int val; cin>>val;
			a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1] + val;
		}

	long long res = -1;
	for (int i = 1; i<=n-k+1; ++i)
		for (int j = 1; j<=m-k+1; ++j)
		{
			res = max(res, a[i+k-1][j+k-1] - a[i+k-1][j-1] - a[i-1][j+k-1] + a[i-1][j-1]);
		}
		
	cout<<res;
	return 0;
}