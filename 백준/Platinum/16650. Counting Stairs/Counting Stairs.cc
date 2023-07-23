#include <bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD (ll)(998244353)

using namespace std;

ll DP[451][100001]{ 0 };

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

ll solve(ll stage, ll remain)
{
	if (remain == 0)
		return 1;

	if (stage <= 0)
		return 0;

	ll& ret = DP[stage][remain];

	if (ret != -1)
		return ret;

	ret = 0;

	add_mod(ret, solve(stage - 1, remain));

	if (remain >= stage)
		add_mod(ret, solve(stage, remain - stage));

	return ret;
}

ll T, A;

void precomp()
{
	for (ll i = 1; i <= 450; i++)
	{
		for (ll j = i; j <= 100000; j++)
			solve(i, j);
	}
}

void act()
{
	ll ret = 0;

	ll start = (A % 2 == 0) ? 2 : 1;

	for (ll i = start; (i <= 450 && i * i <= A); i += 2) // 발판이 start.
		add_mod(ret, solve(i, (A - (i * i)) / 2));

	cout << ret << '\n';
}

int main()
{
	fastio;

	cin >> T;

	memset(DP, -1, sizeof(DP));

	precomp();

	while (T--)
	{
		cin >> A;

		act();
	}
}