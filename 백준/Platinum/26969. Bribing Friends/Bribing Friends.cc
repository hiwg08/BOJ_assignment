#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long

using namespace std;

ll N, A, B;

struct info
{
	ll P, C, X;
	info(ll _p, ll _c, ll _x)
		:P(_p), C(_c), X(_x)
	{}
};

vector<info> V;

ll dp[2001][2001][2]{ 0 };

ll solve(ll idx, ll price, ll none)
{
	if (idx >= N)
		return 0;

	ll& ret = dp[idx][price][none];

	if (ret != -1)
		return ret;

	auto [p, c, x] = V[idx];

	ret = solve(idx + 1, price, none);

	if (none == 1) // 할인을 해야하는 경우
	{
		if (price - c * x > 0)
			ret = max(ret, solve(idx + 1, price - c * x, 1) + p);
		else
		{
			ll discount = c - (price / x);

			if (A >= discount)
				ret = max(ret, solve(idx + 1, A - discount, 0) + p);
		}
	}
	else // 못 하는 경우
	{
		if (price - c >= 0)
			ret = max(ret, solve(idx + 1, price - c, 0) + p);
	}

	return ret;
}

int main()
{
	cin >> N >> A >> B;

	for (ll i = 0, q, w, e; i < N; i++)
	{
		cin >> q >> w >> e;
		info IN(q, w, e);
		V.push_back(IN);
	}

	sort(V.begin(), V.end(), [&](auto a, auto b) {
		return a.X < b.X;
	});

	memset(dp, -1, sizeof(dp));

	cout << solve(0, B, 1);
}