#include <bits/stdc++.h>

using namespace std;

int calculate(int a, int b, int c) {
    if (min(a, c) > b || b > max(a, c)) return 1;
    return 0;
}

int a[1000006], n, q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    int res = 0;
    for(int i = 2; i < n; i++) 
        res += calculate(a[i - 1], a[i], a[i + 1]);
    while(q--){
        char t; cin >> t;
        int p, y; 
        cin >> p >> y;
        int tmp = 0;
        if (1 < p && p < n) {
            tmp += calculate(a[p - 1], y, a[p + 1]) - calculate(a[p - 1], a[p], a[p + 1]);
            if (p - 2 > 0) tmp += calculate(a[p - 2], a[p - 1], y) - calculate(a[p - 2], a[p - 1], a[p]);
            if (p + 2 <= n) tmp += calculate(y, a[p + 1], a[p + 2]) - calculate(a[p], a[p + 1], a[p + 2]);
        } else if (p == 1) {
            if (p + 2 <= n) tmp += calculate(y, a[p + 1], a[p + 2]) - calculate(a[p], a[p + 1], a[p + 2]);
        } else {
            if (p - 2 > 0) tmp += calculate(a[p - 2], a[p - 1], y) - calculate(a[p - 2], a[p - 1], a[p]);
        }

        cout << res + tmp << '\n';
        if (t == 'P') {
            res += tmp;
            a[p] = y;
        }
    }
    return 0;
}