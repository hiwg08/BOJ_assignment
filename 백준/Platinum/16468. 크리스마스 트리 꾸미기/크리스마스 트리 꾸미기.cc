#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(100030001)

using namespace std;

ll N, L;

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
		if (height >= 2 && state == 0)
			return 1;
		if (height == 1 && state == 1)
			return 1;
		return 0;
	}

	ll& ret = DP[size][height][state];

	if (ret != -1)
		return ret;
	
	if (state == 0) // 결국 0인 것도... 1인 것의 '총 합'이 되니까... 그러면 1인 것만 신경 써주면 될라나?
	{
		ll nu = 0;

		for (ll i = height - 1; i >= 1; i--)
			add_mod(nu, solve(size, i, 1));

		return ret = nu;
	}

	ret = 0;

	for (ll i = size - 1; i >= 0; i--)
	{
		ll L = i, R = size - 1 - i;

		if (L == 0)
		{
			ll R1 = solve(R, height - 1, 1);

			add_mod(ret, R1);
		}
		else if (R == 0)
		{
			ll L1 = solve(L, height - 1, 1);
		
			add_mod(ret, L1);
		}
		else
		{
			ll L1 = solve(L, height - 1, 1);
			ll L2 = solve(L, height - 1, 0);
			ll R1 = solve(R, height - 1, 1);
			ll R2 = solve(R, height - 1, 0);
			
			ll A = ((L2 % MOD) * (R1 % MOD)) % MOD;
			ll B = ((L1 % MOD) * (R2 % MOD)) % MOD;
			ll C = ((L1 % MOD) * (R1 % MOD)) % MOD;

			ll nxt = 0;

			add_mod(nxt, A);
			add_mod(nxt, B);
			add_mod(nxt, C);

			ret += nxt;
		}
	}

	return ret;
}

int main()
{
	cin >> N >> L;

	memset(DP, -1, sizeof(DP));

	cout << solve(N, L, 1);
}