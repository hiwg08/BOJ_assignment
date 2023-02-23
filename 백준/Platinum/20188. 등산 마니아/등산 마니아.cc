#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

pll DP[300001];

vector<ll> Tree[300001];

ll N, total, last;

void Init()
{
	for (ll i = 0; i <= 300000; i++)
		DP[i] = { -1, -1 };
}

pll solve(ll Idx, ll before)
{
	pll& ret = DP[Idx];

	if (ret.x != -1)
		return ret;

	ret = { 0, 0 };

	for (auto& e : Tree[Idx])
	{
		if (e == before)
			continue;

		pll T1 = solve(e, Idx);

		ret.x += T1.x + T1.y + 1;
		ret.y += T1.y + 1;
	}

	return ret;
}

void dfs(ll Idx, ll before, ll level, ll params)
{
	ll sum = params + DP[Idx].x + (level * DP[Idx].y);

	Idx == N ? last += sum : total += sum;

	for (auto& e : Tree[Idx])
	{
		if (e == before)
			continue;

		ll spirit = N - 1 - DP[Idx].y;

		ll sec = DP[Idx].y - DP[e].y - 1;

		ll remain = level + 1 + params + spirit;

		ll nxt = (DP[Idx].x - (DP[e].x + DP[e].y + 1)) + ((level + 1) * sec);

		dfs(e, Idx, level + 1, remain + nxt);
	}
}

int main()
{
	fastio;

	cin >> N;

	for (ll i = 0, a, b; i < N - 1; i++)
	{
		cin >> a >> b;
		Tree[a].push_back(b);
		Tree[b].push_back(a);
	}

	Init();

	DP[1] = solve(1, -1);

	dfs(1, -1, 0, 0);

	cout << (total - last) / 2 + last << '\n';
}