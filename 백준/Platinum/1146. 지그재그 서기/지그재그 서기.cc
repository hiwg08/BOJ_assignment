#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(1e6)

using namespace std;

ll N, DP1[101][101]{ 0 }, DP2[101][2][2]{ 0 };

void add_mod(ll& stand, ll pre)
{
	stand += pre, stand %= MOD;
}

void mul_mod(ll& stand, ll pre)
{
	stand *= pre, stand %= MOD;
}

ll solve(ll n, ll r)
{
	if (n == r || r == 0)
		return 1;

	ll& ret = DP1[n][r];

	if (ret != -1)
		return ret;

	return ret = ((solve(n - 1, r) % MOD) + (solve(n - 1, r - 1) % MOD)) % MOD;
}

void get_fac()
{
	memset(DP1, -1, sizeof(DP1));

	for (ll i = 1; i <= 100; i++)
	{
		for (ll j = 1; j <= i; j++)
			solve(i, j);
	}
}

void Init()
{
	DP2[1][0][1] = 1, DP2[1][1][0] = 1;

	DP2[2][0][0] = 1, DP2[2][1][1] = 1;

	for (ll i = 3; i <= N; i++)
	{
		if (i % 2 == 0)
		{
			add_mod(DP2[i][0][0], DP2[i - 1][1][0]);
			add_mod(DP2[i][1][1], DP2[i - 1][1][0]);

			for (ll j = 2; j < i; j++)
			{
				ll Ans1 = 1, Ans2 = 1;
				mul_mod(Ans1, DP2[j - 1][0][0]), mul_mod(Ans1, DP2[i - j][1][0]), mul_mod(Ans1, DP1[i - 1][j - 1]);
				mul_mod(Ans2, DP2[j - 1][1][0]), mul_mod(Ans2, DP2[i - j][1][1]), mul_mod(Ans2, DP1[i - 1][j - 1]);
				
				add_mod(DP2[i][0][0], Ans1);
				add_mod(DP2[i][1][1], Ans2);
			}
		}
		else
		{
			add_mod(DP2[i][0][1], DP2[i - 1][0][0]);
			add_mod(DP2[i][0][1], DP2[i - 1][1][1]);

			for (ll j = 2; j < i; j++)
			{
				ll Ans1 = 1, Ans2 = 1;
				mul_mod(Ans1, DP2[j - 1][0][0]), mul_mod(Ans1, DP2[i - j][1][1]), mul_mod(Ans1, DP1[i - 1][j - 1]);
				mul_mod(Ans2, DP2[j - 1][1][0]), mul_mod(Ans2, DP2[i - j][1][0]), mul_mod(Ans2, DP1[i - 1][j - 1]);

				add_mod(DP2[i][0][1], Ans1);
				add_mod(DP2[i][1][0], Ans2);
			}
		}
	}
}

int main()
{
	cin >> N;

	get_fac();

	Init();

	if (N == 1)
		cout << 1 << '\n';

	else
	{
		ll Ans = 0;

		for (ll i = 0; i < 2; i++)
		{
			for (ll j = 0; j < 2; j++)
				add_mod(Ans, DP2[N][i][j]);
		}

		cout << Ans << '\n';
	}
}