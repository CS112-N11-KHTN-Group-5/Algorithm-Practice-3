#include <iostream>
#include <algorithm>
#include <map>
#define llong long long

using namespace std;

int cal(int x, int y, int z) {
    if (min(x, z) > y || y > max(x, z))
        return 1;
    return 0;
}

int a[1000006], n, q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int ans = 0;
    // Calculate initial answer
    for (int i = 2; i < n; ++i)
        ans += cal(a[i - 1], a[i], a[i + 1]);

    while (q--) {
        char t;
        cin >> t;
        int p, val;
        cin >> p >> val;

        int tmp = 0;
        if (1 < p && p < n) {
            tmp += cal(a[p - 1], val, a[p + 1]) - cal(a[p - 1], a[p], a[p + 1]);
            if (p - 2 > 0)
                tmp += cal(a[p - 2], a[p - 1], val) - cal(a[p - 2], a[p - 1], a[p]);
            if (p + 2 <= n)
                tmp += cal(val, a[p + 1], a[p + 2]) - cal(a[p], a[p + 1], a[p + 2]);
        } else if (p == 1) {
            if (p + 2 <= n)
                tmp += cal(val, a[p + 1], a[p + 2]) - cal(a[p], a[p + 1], a[p + 2]);
        } else {
            if (p - 2 > 0)
                tmp += cal(a[p - 2], a[p - 1], val) - cal(a[p - 2], a[p - 1], a[p]);
        }

        cout << ans + tmp << '\n';
        if (t == 'P') {
            ans += tmp;
            a[p] = val;
        }
    }

    return 0;
}