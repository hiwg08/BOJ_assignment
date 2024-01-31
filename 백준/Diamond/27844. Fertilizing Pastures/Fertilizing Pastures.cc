#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

pll dp1[200001];

ll dp2[200001]{ 0 };

ll max_d[200001]{ 0 };

ll ano[200001]{ 0 };

ll N, T;

vector<ll> Tree[200001];

ll sts[200001]{ 0 };

void init()
{
	for (ll i = 1; i <= N; i++)
		dp1[i] = { -1, -1 };

	memset(dp2, -1, sizeof(dp2));
}

pll solve(ll Idx, ll before)
{
	pll& ret = dp1[Idx];

	if (ret.x != -1)
		return ret;

	bool chk = false;

	ret = { sts[Idx], 1 };
	max_d[Idx] = 0;

	for (auto e : Tree[Idx])
	{
		if (e == before)
			continue;

		chk = true;

		pll T1 = solve(e, Idx);

		max_d[Idx] = max(max_d[Idx], max_d[e] + 1);
		ret.x += T1.x;
		ret.y += T1.y;
	}

	return ret;
}

void after_comp(ll Idx, ll before)
{
	bool chk = false;

	for (auto e : Tree[Idx])
	{
		if (e == before)
			continue;

		chk = true;

		after_comp(e, Idx);
	}

	if (!chk)
		return;

	sort(Tree[Idx].begin(), Tree[Idx].end(), [&](auto a, auto b) {
		auto [q1, q2] = dp1[a];
		auto [w1, w2] = dp1[b];

		return q2 * w1 < q1 * w2;
	});
}

ll real_solve(ll Idx, ll before)
{
	vector<ll>tmp; 
	tmp.resize(Tree[Idx].size() + 2);

	ll& ret = dp2[Idx];

	if (ret != -1)
		return ret;
	
	bool chk = false;

	ret = 0;

	ll nu = 1;

	for (auto e : Tree[Idx])
	{
		if (e == before)
			continue;

		chk = true;

		ll T1 = real_solve(e, Idx);

		ret += T1;
		ret += (nu * dp1[e].x);

		nu += 2 * dp1[e].y;
	}

	for (ll i = (ll)Tree[Idx].size() - 1; i >= 0; i--)
		tmp[i] = tmp[i + 1] + dp1[Tree[Idx][i]].x;

	nu = 0, ano[Idx] = 8e18;

	chk = false;

	for (ll i = 0; i < (ll)Tree[Idx].size(); i++)
	{
		if (Tree[Idx][i] == before)
			continue;

		chk = true;

		ll Q = Tree[Idx][i];
		
		if (max_d[Q] + 1 == max_d[Idx])
			ano[Idx] = min(ano[Idx], dp2[Idx] - dp2[Q] - (nu * dp1[Q].x) - (2 * dp1[Q].y * tmp[i + 1]) + 2 * (dp1[Idx].y - 1 - dp1[Q].y) * dp1[Q].x + ano[Q]);

		nu += 2 * dp1[Q].y;
	}

	if (!chk)
		ano[Idx] = 0;

	return ret;
}

int main()
{
	cin >> N >> T;

	for (ll i = 2, a, b; i <= N; i++)
	{
		cin >> a >> b;

		Tree[a].push_back(i);

		sts[i] = b;
	}

	init();

	solve(1, -1);

	after_comp(1, -1);

	real_solve(1, -1);

	if (T == 0)
		cout << (N - 1) * 2 << " " << dp2[1];
	else
		cout << (N - 1) * 2 - max_d[1] << " " << ano[1];
}