#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(1e9 + 7)

using namespace std;

ll N, A, total;

ll DP[2][11][11][1001][2]{ 0 };

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

void init()
{
	for (ll i = 0; i <= 9; i++)
	{
		for (ll j = i; j >= 1; j--)
		{
			ll diff = i - j;

			DP[0][i][diff][1][1]++;
		}
	}

	for (ll zari = 3; zari <= N; zari++) // zari는 무시하면 된다.
	{
		for (ll pre = 0; pre <= 9; pre++)
		{
			for (ll bef = pre; bef >= 0; bef--)
			{
				ll diff = pre - bef;

				for (ll again = bef; again >= 0; again--)
				{
					ll ano_diff = bef - again;

					for (ll stand = zari - 2; stand >= 1; stand--)
					{
						if (diff != ano_diff)
						{
							add_mod(DP[zari % 2][pre][diff][stand][1], DP[(zari - 1) % 2][bef][ano_diff][stand][0]);
							add_mod(DP[zari % 2][pre][diff][stand + 1][0], DP[(zari - 1) % 2][bef][ano_diff][stand][1]);
						}
						else
						{
							add_mod(DP[zari % 2][pre][diff][stand][1], DP[(zari - 1) % 2][bef][ano_diff][stand][0]);
							add_mod(DP[zari % 2][pre][diff][stand][1], DP[(zari - 1) % 2][bef][ano_diff][stand][1]);
						}
					}
				}
			}
		}

		memset(DP[(zari - 1) % 2], 0, sizeof(DP[(zari - 1) % 2]));
	}
}

void solve()
{
	for (ll pre = 0; pre <= 9; pre++)
	{
		for (ll bef = pre; bef >= 0; bef--)
		{
			ll diff = pre - bef;

			add_mod(total, DP[N % 2][pre][diff][A][0]);
			add_mod(total, DP[N % 2][pre][diff][A][1]);
		}
	}
}

int main()
{
	cin >> N >> A;

	if (N == 1)
	{
		if (A == 1)
			cout << 9;
		else
			cout << 0;

		exit(0);
	}

	init();

	solve();

	cout << total;
}