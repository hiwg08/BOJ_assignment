#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define MOD (ll)(1e9)

using namespace std;

ll a, b;

vvi solve(ll pows)
{
	if (pows == 0)
		return { {1, 0}, {0, 1} };

	vvi ret = { {0, 0}, {0, 0} };

	if (pows % 2 != 0)
	{
		vvi T = solve(pows - 1);

		vvi Q = { {1, 1},  {1, 0} };

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					ret[i][j] += ((T[i][k] % MOD) * (Q[k][j] % MOD)) % MOD;
					ret[i][j] %= MOD;
				}
			}
		}

		return ret;
	}

	vvi T = solve(pows / 2);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				ret[i][j] += ((T[i][k] % MOD) * (T[k][j] % MOD)) % MOD;
				ret[i][j] %= MOD;
			}
		}
	}

	return ret;
}

int main()
{
	cin >> a >> b;

	cout << (solve(b + 2)[0][1] - solve(a + 1)[0][1] + MOD) % MOD << '\n';
}