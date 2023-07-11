/// hhoangcp

#include <iostream>
#include <algorithm>
#include <map>
#define llong long long

using namespace std;

llong mod = 1e9 + 7;
map<llong, llong> f;

llong fibo(llong n) {
    if (n < 0) return 0;
    if (f.count(n)) return f[n];

    if (n & 1) return f[n] = (fibo(n / 2) * (fibo(n / 2 + 1) + fibo(n / 2 - 1))) % mod;
    return f[n] = (fibo(n / 2) * fibo(n / 2) + fibo(n / 2 - 1) * fibo(n / 2 - 1)) % mod;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    f[0] = f[1] = 1;
    llong n; cin >> n;
    cout << fibo(n - 1);

    return 0;
}