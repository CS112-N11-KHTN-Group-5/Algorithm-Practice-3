/// hhoangcp

#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

vector<vector<llong>> sum;
int n, m, k;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m >> k;
    sum.assign(n + 1, vector<llong>(m + 1, 0));

    llong ans = 0;
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j) {
        int a; cin >> a;
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a;

        if (i >= k && j >= k) ans = max(ans, sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k]);
    }

    cout << ans;

    return 0;
}