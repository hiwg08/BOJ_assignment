#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define MOD (ll)(1e9 + 7)
#define x first
#define y second

using namespace std;

ll N;

vector<pll> Tree[100001];

pll dp[100001];

void init()
{
	for (ll i = 1; i <= N; i++)
		dp[i] = { -1, -1 };
}

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

pll solve(ll Idx, ll bef)
{
	pll& ret = dp[Idx];

	if (ret.x != -1)
		return ret;

	ret = { 0, 0 };

	ll sum = 0;

	for (auto& e : Tree[Idx])
	{
		if (e.x == bef)
			continue;

		pll T1 = solve(e.x, Idx);

		ll stat = T1.y;

		add_mod(stat, 1);
		mul_mod(stat, e.y);
		
		add_mod(ret.x, T1.x);
		add_mod(ret.x, stat);

		add_mod(ret.y, stat);

		ll K = sum;
		mul_mod(K, stat);
		add_mod(ret.x, K);

		add_mod(sum, stat);
	}
	
	return ret;
}

int main()
{
	cin >> N;

	for (ll i = 0, A, B, W; i < N - 1; i++)
	{
		cin >> A >> B >> W;

		Tree[A].push_back({ B, W });
		Tree[B].push_back({ A, W });
	}

	init();

	cout << solve(1, -1).x;
}
