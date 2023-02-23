#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, DP[10001]{ 0 };

vector<pll> V;

bool cmp(pll a, pll b)
{
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

ll solve(ll Idx)
{
	if (Idx >= N)
		return 0;

	ll& ret = DP[Idx];

	if (ret != -1)
		return ret;

	ret = LLONG_MAX;

	ll remain = abs(V[Idx].y) * 2;

	for (ll i = Idx; i < N; i++)
	{
		ll Interval = max(V[i].x - V[Idx].x, abs(V[i].y) * 2);

		if (remain < Interval)
		{
			ret = min(ret, solve(i) + remain);
			remain = Interval;
		}
	}

	return ret = min(ret, remain);
}

int main()
{
	fastio;

	cin >> N; V.resize(N);

	for (auto& iv : V)
		cin >> iv.x >> iv.y;

	sort(V.begin(), V.end(), cmp);

	memset(DP, -1, sizeof(DP));

	cout << solve(0) << '\n';
}