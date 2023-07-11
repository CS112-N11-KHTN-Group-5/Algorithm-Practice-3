#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define Matrix vector<vector<ll>>
const ll MOD = 1e9 + 7;
const ll MOD2 = MOD * MOD;

Matrix createMatrix(int rows, int cols)
{
    return Matrix(rows, vector<ll>(cols));
}

Matrix multiply(Matrix A, Matrix B)
{
    int n = A.size();
    int m = B[0].size();
    int p = B.size();

    Matrix result = createMatrix(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
                if (result[i][j] >= MOD2)
                    result[i][j] -= MOD2;
            }
            result[i][j] %= MOD;
        }
    }
    return result;
}

int main()
{
    ll n;
    cin >> n;

    Matrix base = {{0, 1}, {1, 1}};
    Matrix result = {{0, 1}};

    while (n > 0)
    {
        if (n & 1)
            result = multiply(result, base);
        base = multiply(base, base);
        n >>= 1;
    }

    cout << result[0][0] << endl;
    return 0;
}