#include <bits/stdc++.h>
using namespace std;


long long n,k;
const long long mod = 1e9+7;

struct matrix
{
    long long a[2][2];

    void init()
    {
        a[0][0] = 1;
        a[1][0] = 1;
    }

    void prodmtx()
    {
        a[0][0] = 1; a[0][1] = 1;
        a[1][0] = 1;
    }

    matrix operator * (matrix const &T) const
    {
        matrix res;
        for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            res.a[i][j] = 0;
            for (int k = 0; k < 2; k++)
                res.a[i][j] = (1LL*res.a[i][j] + a[i][k]*T.a[k][j]%mod)%mod;
        }
        return res;
    }
};


matrix initmtx;
matrix prodmtx;

matrix pwr(matrix x, long long y)
{
    if (y == 1) return prodmtx;
    x = pwr(x,y/2);
    x = x*x;
    if (y%2 == 0)
        return x;
    else
        return x*prodmtx;
}


void inp()
{
    cin >> n;
}

void proc()
{
    initmtx.init();
    prodmtx.prodmtx();

    if (n <= 2)
    {
        cout << 1;
        return;
    }
    matrix tmp;
    tmp = pwr(prodmtx,n-2);
    //cout << tmp.a[0][0] << '\n' << tmp.a[1][0] << '\n';
    initmtx = tmp*initmtx;

    cout << initmtx.a[0][0];
}


int main()
{
    inp();
    proc();
    return 0;
}