#include <bits/stdc++.h>
using namespace std;

int n,q;
int a[1000005];



void inp()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

int is_extrema(int i)
{
    if (i <= 1 || i >= n) return 0;
    bool t[2][2];
    if (i == 1) t[0][0] = t[0][1] = 1;
    else
    {
        t[0][0] = a[i] < a[i-1];
        t[0][1] = a[i] > a[i-1];
    }
    if (i == n) t[1][0] = t[1][1] = 1;
    else
    {
        t[1][0] = a[i] < a[i+1];
        t[1][1] = a[i] > a[i+1];
    }
    return (t[0][0] && t[1][0]) || (t[0][1] && t[1][1]);
}


void proc()
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += is_extrema(i);

    while (q--)
    {
        int x,y;
        char c;
        cin >> c >> x >> y;
        int old = a[x];
        int oldsum = is_extrema(x) + is_extrema(x+1) + is_extrema(x-1);
        a[x] = y;
        int newsum = is_extrema(x) + is_extrema(x+1) + is_extrema(x-1);
        cout << sum + newsum - oldsum << '\n';
        a[x] = old;

        if (c == 'P')
        {
            a[x] = y;
            sum = sum + newsum - oldsum;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("file.inp","r",stdin);
    inp();
    proc();
    return 0;
}