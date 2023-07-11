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

  int n, q;
  cin >> n >> q;
  vector<int> a(n + 2);
  vector<int> new_val(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  auto calc = [&](int l, int r) -> int {
    l = max(2, l);
    r = min(n - 1, r);
    int total = 0;
    for (int i = l; i <= r; i++) {
      if (a[i] > a[i - 1] && a[i] > a[i + 1])
        total++;
      else if (a[i] < a[i - 1] && a[i] < a[i + 1])
        total++;
    }
    return total;
  };

  int total = calc(1, n);
  for (int i = 1; i <= q; i++) {
    int pos, val;
    char typ;
    cin >> typ >> pos >> val;
    if (new_val[pos]) {
      int diff = -1 * calc(pos - 1, pos + 1);
      a[pos] = new_val[pos];
      diff += calc(pos - 1, pos + 1);
      total += diff;
      new_val[pos] = 0;
    }
    if (typ == 'T') {
      auto prev = a[pos];
      int diff = -1 * calc(pos - 1, pos + 1);
      a[pos] = val;
      diff += calc(pos - 1, pos + 1);
      cout << total + diff << "\n";
      a[pos] = prev;
    } else {
      int diff = -1 * calc(pos - 1, pos + 1);
      a[pos] = val;
      diff += calc(pos - 1, pos + 1);
      cout << total + diff << "\n";
      new_val[pos] = val;
      total += diff;
    }
  }
  return 0;
}