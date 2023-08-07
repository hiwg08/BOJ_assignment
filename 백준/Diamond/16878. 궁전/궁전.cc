#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MOD (ll)(1e9 + 7)

using namespace std;

ll T, N;

ll dp[10000001]{ 0 };

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

void mul_mod(ll& ret, ll params)
{
	ret *= params;
	ret %= MOD;
}

void sub_mod(ll& ret, ll params)
{
	ret = (ret - params + MOD) % MOD;
}

void precomp()
{
	dp[0] = dp[1] = 1;
	dp[2] = dp[3] = 0;
	dp[4] = 2;

	for (ll i = 5; i <= 10000000; i++)
	{
		ll Q = i + 1;
		mul_mod(Q, dp[i - 1]);

		ll W = i - 2;
		mul_mod(W, dp[i - 2]);
		sub_mod(Q, W);

		ll E = i - 5;
		mul_mod(E, dp[i - 3]);
		sub_mod(Q, E);

		ll R = i - 3;
		mul_mod(R, dp[i - 4]);
		add_mod(Q, R);

		dp[i] = Q;
	}
}

int main()
{
	fastio;

	precomp();

	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << dp[N] << '\n';
	}
}