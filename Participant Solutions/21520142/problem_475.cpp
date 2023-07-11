#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

const int MAXN = 2e5 + 6;
const int MOD = 1e9 + 7;

int main(int argc, char const *argv[]) {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
  }

  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<ll>> a(n + 1, vector<ll>(m + 1));
  vector<vector<ll>> s(n + 1, vector<ll>(m + 1));

  auto sum = [&](int x, int y, int u, int v) -> ll {
    if (x < 1 || y < 1)
      return 0ll;
    else
      return s[u][v] - s[x - 1][v] - s[u][y - 1] + s[x - 1][y - 1];
  };

  ll res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      s[i][j] = s[i - 1][j] + s[i][j - 1] + a[i][j] - s[i - 1][j - 1];
      res = max(res, sum(i - k + 1, j - k + 1, i, j));
    }
  }
  cout << res;
  return 0;
}