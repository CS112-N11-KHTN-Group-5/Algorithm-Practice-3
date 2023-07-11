#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    #ifdef Keqing
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #else
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    #endif

    int n,m,k; cin >> n >> m >> k;
    vector<vector<ll>> f(n+1, vector<ll>(m+1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> f[i][j];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + f[i][j];
    
    ll res = 0;
    for (int i = k; i <= n; i++)
        for (int j = k; j <= m; j++)
            res = max(res, f[i][j] - f[i-k][j] - f[i][j-k] + f[i-k][j-k]);
    
    cout << res;
    return 0;
}