#include <iostream>
using namespace std;

int n, a[1000005];

int isPeak(int x, int y)
{
    if (x <= 1)
        return 0;
    if (x >= n)
        return 0;
    if ((y > max(a[x - 1], a[x + 1])) || (y < min(a[x - 1], a[x + 1])))
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q, cnt = 0;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (i > 2)
        {
            cnt += isPeak(i - 1, a[i - 1]);
        }
    }

    while (q--)
    {
        char c;
        int x, y;
        cin >> c >> x >> y;
        int left = isPeak(x - 1, a[x - 1]);
        int right = isPeak(x + 1, a[x + 1]);

        int temp = a[x];
        int tempcnt = cnt;
        a[x] = y;
        cnt += (isPeak(x, a[x]) - isPeak(x, temp) + isPeak(x - 1, a[x - 1]) - left + isPeak(x + 1, a[x + 1]) - right);

        cout << cnt << "\n";
        if (c == 'T')
        {
            a[x] = temp;
            cnt = tempcnt;
        }
    }

    return 0;
}