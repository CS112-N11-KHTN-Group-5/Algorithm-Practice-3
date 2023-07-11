// Fibonacci Series using Optimized Method
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
void multiply(long long F[2][2], long long M[2][2]);
void power(long long F[2][2], long long n);

int fib(long long n)
{
	long long F[2][2] = { { 1, 1 }, { 1, 0 } };
	if (n == 0)
		return 0;
	power(F, n - 1);

	return F[0][0];
}

void power(long long F[2][2], long long n)
{
	if (n == 0 || n == 1)
		return;
	long long M[2][2] = { { 1, 1 }, { 1, 0 } };

	power(F, n / 2);
	multiply(F, F);

	if (n % 2 != 0)
		multiply(F, M);
}

void multiply(long long F[2][2], long long M[2][2])
{
	long long x = ((F[0][0] * M[0][0]) % MOD + (F[0][1] * M[1][0]) % MOD) % MOD;
	long long y = ((F[0][0] * M[0][1]) % MOD + (F[0][1] * M[1][1]) % MOD) % MOD;
	long long z = ((F[1][0] * M[0][0]) % MOD + (F[1][1] * M[1][0]) % MOD) % MOD;
	long long w = ((F[1][0] * M[0][1]) % MOD + (F[1][1] * M[1][1]) % MOD) % MOD;

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

int main()
{
	long long n;
	cin>>n;
	cout << fib(n);

	return 0;
}