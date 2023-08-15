#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, P;

ll DP[151][151]{ 0 };

ll fib[151]{ 0 };

ll limi[151]{ 0 };

void mul_mod(ll& ret, ll params)
{
	ret *= params;
	ret %= P;
}

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= P;
}

void precomp()
{
	fib[0] = 1, fib[1] = 2;

	for (ll i = 2; i <= 150; i++)
		fib[i] = ((fib[i - 1] % P) + (fib[i - 2] % P)) % P;

	limi[1] = 1;

	for (ll i = 2; i <= 150; i++)
		limi[i] = limi[i - 1] + i;
}

int main()
{
	cin >> N >> P;

	precomp();

	DP[0][0] = 1;

	for (ll i = 1; i <= N; i++)
	{
		for (ll j = 1; j <= i; j++)
		{
			for (ll k = 1; k <= j; k++)
			{
				if (k == 1)
				{
					if (i - 1 < 0 || j - k < 0)
						continue;
					ll Q1 = 2;
					mul_mod(Q1, DP[i - 1][j - k]);
					add_mod(DP[i][j], Q1);
				}
				else
				{
					for (ll q = k - 1; q <= limi[k - 1]; q++)
					{
						if (i - q - k < 0 || j - k < 0 || q < 0 || k - 1 < 0)
							continue;
						ll Q1 = fib[k];
						mul_mod(Q1, DP[q][k - 1]);
						mul_mod(Q1, DP[i - q - k][j - k]);
						add_mod(DP[i][j], Q1);
					}
				}
			}
		}
	}

	ll ans = 0;

	for (ll i = N; i >= 1; i--)
		add_mod(ans, DP[N][i]);

	cout << ans;
}