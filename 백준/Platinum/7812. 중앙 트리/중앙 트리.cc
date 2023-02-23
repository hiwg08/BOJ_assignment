#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, ans;

vector<pll> Tree[10001];

pll DP[10001];

void Init()
{
	ans = LLONG_MAX;

	for (ll i = 0; i <= 10000; i++)
	{
		DP[i] = { -1, -1 };
		Tree[i].clear();
	}
}

pll solve_1(ll Idx, ll Before)
{
	pll& ret = DP[Idx];

	if (ret.x != -1 && ret.y != -1)
		return ret;

	ret = { 0, 1 };

	for (ll i = 0; i < (ll)Tree[Idx].size(); i++)
	{
		if (Tree[Idx][i].x == Before)
			continue;

		pll T1 = solve_1(Tree[Idx][i].x, Idx);

		ret.x += (T1.y * Tree[Idx][i].y) + T1.x;
		ret.y += T1.y;
	}

	return ret;
}

void solve_2(ll Idx, ll Before, ll upper)
{
	for (ll i = 0; i < (ll)Tree[Idx].size(); i++)
	{
		if (Tree[Idx][i].x == Before)
			continue;

		ll Fir = DP[Idx].x;
		ll Sec = DP[Tree[Idx][i].x].x;
		ll Tir = (DP[Tree[Idx][i].x].y * Tree[Idx][i].y);

		ll lower = Fir - Sec - Tir;

		ll weight = (DP[0].y - DP[Tree[Idx][i].x].y) * Tree[Idx][i].y;

		ll T = DP[Tree[Idx][i].x].x + lower + upper + weight;

		ans = min(ans, T);

		solve_2(Tree[Idx][i].x, Idx, lower + upper + weight);
	}
}

int main()
{
	fastio;

	while (true)
	{
		cin >> N;

		if (N == 0)
			break;

		Init();

		for (ll i = 0, a, b, c; i < N - 1; i++)
		{
			cin >> a >> b >> c;
			Tree[a].push_back({ b, c });
			Tree[b].push_back({ a, c });
		}

		DP[0] = solve_1(0, -1);

		solve_2(0, -1, 0);

		ans == LLONG_MAX ? cout << 0 << '\n' : cout << ans << '\n';
	}
}