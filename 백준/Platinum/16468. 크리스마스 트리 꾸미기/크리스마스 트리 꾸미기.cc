#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(100030001)

using namespace std;

ll N, M;

ll DP[301][301][2]{ 0 };

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

ll solve(ll size, ll height, ll state)
{
	if (height <= 0)
		return 0;

	if (size == 1)
	{
		if (height == 1)
			return 1;
		return 0;
	}

	ll& ret = DP[size][height][state];

	if (ret != -1)
		return ret;

	if (state == 0)
	{
		ll nu = 0;

		for (ll i = height; i >= 1; i--)
			add_mod(nu, solve(size, i, 1));

		return ret = nu;
	}

	ret = 0;

	for (ll i = size - 1; i >= 0; i--)
	{
		ll L = i, R = size - 1 - i;

		if (L == 0)
		{
			ll R1 = 0;

			if (R >= height - 1)
				R1 = solve(R, height - 1, 1);

			add_mod(ret, R1);
		}
		else if (R == 0)
		{
			ll L1 = 0;

			if (L >= height - 1)
				L1 = solve(L, height - 1, 1);

			add_mod(ret, L1);
		}
		else
		{
			ll L0 = 0, R0 = 0, L1 = 0, R1 = 0;

			if (R >= height - 1)
				R1 = solve(R, height - 1, 1);
			R0 = solve(R, min(height - 1, (ll)R), 0);

			if (L >= height - 1)
				L1 = solve(L, height - 1, 1);
			L0 = solve(L, min(height - 1, (ll)L), 0);

			ll fir = ((R0 % MOD) * (L0 % MOD)) % MOD;

			ll sec = ((R0 % MOD) - (R1 % MOD) + MOD) % MOD;

			ll thi = ((L0 % MOD) - (L1 % MOD) + MOD) % MOD;

			ll fou = ((sec % MOD) * (thi % MOD)) % MOD;

			ll ans = ((fir % MOD) - (fou % MOD) + MOD) % MOD;

			add_mod(ret, ans);
		}
	}

	return ret;
}

int main()
{
	cin >> N >> M;

	memset(DP, -1, sizeof(DP));

	cout << solve(N, M, 1);
}