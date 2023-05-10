#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(1e5)

using namespace std;

ll DP[201][201]{ 0 };

ll N;

string S;

void mul_mod(ll& ret, ll params)
{
	ret *= params;
	ret %= MOD;
}

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

ll calc(ll start, ll end)
{
	if (S[start] == '?' && S[end] == '?')
		return 3;
	if (S[start] != '?' && S[end] == '?')
	{
		if (S[start] == '[' || S[start] == '{' || S[start] == '(')
			return 1;
		return 0;
	}
	if (S[start] == '?' && S[end] != '?')
	{
		if (S[end] == ']' || S[end] == '}' || S[end] == ')')
			return 1;
		return 0;
	}
	if (S[start] != '?' && S[end] != '?')
	{
		if ((S[start] == '[' && S[end] == ']') ||
			(S[start] == '{' && S[end] == '}') ||
			(S[start] == '(' && S[end] == ')'))
			return 1;
		return 0;
	}
	return 0;
}

ll solve(ll start, ll end)
{
	if (start > end)
		return 1;

	ll& ret = DP[start][end];

	if (ret != -1)
		return ret;

	ret = 0;

	for (ll i = start + 1; i < end; i += 2)
	{
		ll a1 = start, a2 = i, b1 = i + 1, b2 = end;

		ll L = calc(a1, a2);

		ret += L * solve(a1 + 1, a2 - 1) * solve(b1, b2);

		if (ret >= MOD)
			ret = MOD + ret % MOD;
	}

	ret += calc(start, end) * solve(start + 1, end - 1);

	if (ret >= MOD)
		ret = MOD + ret % MOD;

	return ret;
}

int main()
{
	cin >> N;

	cin >> S;

	if (N % 2 != 0)
	{
		cout << 0;
		exit(0);
	}

	memset(DP, -1, sizeof(DP));

	ll ans = solve(0, N - 1);

	if (ans >= MOD)
		printf("%05lld", ans % MOD);
	else
		cout << ans;
}