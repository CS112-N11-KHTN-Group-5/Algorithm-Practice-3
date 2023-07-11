#include <bits/stdc++.h>
#include <cstdint>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;

const int MAXN = 2e5 + 6;
const int MOD = 1e9 + 7;

vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b) {
  vector<vector<int>> res(a.size(), vector<int>(b[0].size()));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b[0].size(); j++) {
      res[i][j] = 0;
      for (int k = 0; k < b.size(); k++) {
        res[i][j] += a[i][k] * b[k][j];
        res[i][j] %= MOD;
      }
    }
  }
  return res;
}

vector<vector<int>> pow(vector<vector<int>> mat, int k) {
  if (k == 1)
    return mat;
  vector<vector<int>> res = pow(mat, k / 2);
  res = mul(res, res);
  if (k & 1)
    res = mul(res, mat);
  return res;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
  }

  ll n;
  cin >> n;
  vector<vector<int>> mat = {{1, 1}, {1, 0}};
  mat = pow(mat, n);
  cout << mat[1][0];
  return 0;
}