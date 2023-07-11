#include <bits/stdc++.h>
using namespace std;



int n,m,k;
vector <vector <long long> > a;


void inp()
{
    cin >> n >> m >> k;
    a.resize(n+1,vector<long long>(m+1,0));
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
        cin >> a[i][j];
        a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1];
    }
}

void proc()
{
    long long ans = 0;
    for (int i = 1; i <= n-k+1; i++)
    for (int j = 1; j <= m-k+1; j++)
    {
        int u,v;
        u = i+k-1;
        v = j+k-1;

        ans = max(ans, a[u][v] - a[u][j-1] - a[i-1][v] +a[i-1][j-1]);
    }
    cout << ans;
}


int main()
{
    inp();
    proc();
    return 0;
}