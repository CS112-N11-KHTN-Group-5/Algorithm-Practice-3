#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
ll const mod = 1e9 + 7;

using namespace std;
ll a[2][2] = {{1,1},{1,0}};

void mu(ll n){
    if(n<=1){
        return;
    }
    ll k = n / 2;
    mu(k);
    ll tmp[2][2];
    tmp[0][0] = a[0][0] * a[0][0] % mod + a[0][1] * a[1][0] % mod;
    tmp[0][1] = a[0][0] * a[0][1] % mod + a[0][1] * a[1][1] % mod;
    tmp[1][0] = a[1][0] * a[0][0] % mod + a[1][1] * a[1][0] % mod;
    tmp[1][1] = a[1][0] * a[0][1] % mod + a[1][1] * a[1][1] % mod;
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            tmp[x][y] %= mod;
            a[x][y] = tmp[x][y];
        }
    }
    if(n%2==1){
        tmp[0][0] = a[0][0] + a[0][1];
        tmp[0][1] = a[0][0];
        tmp[1][0] = a[1][0] + a[1][1];
        tmp[1][1] = a[1][0];
        for (int x = 0; x < 2; x++)
        {
            for (int y = 0; y < 2; y++)
            {
                tmp[x][y] %= mod;
                a[x][y] = tmp[x][y];
            }
        }
    }
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            a[x][y] %= mod;
        }
    }

}

int main()
{
    ll n;
    cin >> n;
    mu(n-1);
    ll result = a[0][0];
    result %= mod;
    cout << result;
}