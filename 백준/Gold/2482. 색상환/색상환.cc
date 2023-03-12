#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(1e9 + 3)

using namespace std;

ll DP[1001][1001][2][2]{ 0 }; // Idx, select, one

ll N, K;

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

ll solve(ll Idx, ll select, ll check, ll one)
{
	if (Idx >= N)
	{
		if (select == K)
			return 1;
		return 0;
	}

	ll& ret = DP[Idx][select][check][one];

	if (ret != -1)
		return ret;

	ret = 0;

	if (Idx == 0)
	{
		add_mod(ret, solve(Idx + 1, select + 1, 1, 1));
		add_mod(ret, solve(Idx + 1, select, 0, 0));
	}

	else if (Idx == N - 1)
	{
		if (one)
			add_mod(ret, solve(Idx + 1, select, 1, one));
		else
		{
			if (!check)// false면 선택해도 되고, 안 해도 되고
				add_mod(ret, solve(Idx + 1, select + 1, 1, one));

			add_mod(ret, solve(Idx + 1, select, 0, one));
		}
	}
	
	else
	{
		if (!check)// false면 선택해도 되고, 안 해도 되고
			add_mod(ret, solve(Idx + 1, select + 1, 1, one));

		add_mod(ret, solve(Idx + 1, select, 0, one));
	}

	return ret;
}

int main()
{
	cin >> N >> K;

	memset(DP, -1, sizeof(DP));

	cout << solve(0, 0, 0, 0) << '\n';
}