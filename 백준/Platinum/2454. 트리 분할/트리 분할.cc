#include <bits/stdc++.h>
#define fasti ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define vl vector<ll>
#define x first
#define y second

using namespace std;

ll N, K;

vector<vl> tree;

pll dp[300001];

void init()
{
	for (ll i = 0; i <= N; i++)
		dp[i] = { -1, -1 };
}

pll solve(ll Idx, ll before)
{
	auto& [ni, nj] = dp[Idx];

	if (ni != -1)
		return { ni, nj };

	ll total = 0;

	vector<pll> V;

	bool flag = false;

	for (auto e : tree[Idx])
	{
		if (e == before)
			continue;

		flag = true;

		auto [ti, tj] = solve(e, Idx);

		V.push_back({ ti, tj });

		total += ti;
	}

	if (!flag)
		return { 1, 1 };

	ni = total + 1, nj = 1;

	sort(V.begin(), V.end(), [&](pll a, pll b) {
		return a.y < b.y;
	});

	if ((ll)V.size() >= 1 && V[0].y < K)
		ni = total, nj = V[0].y + 1;

	if ((ll)V.size() >= 2 && V[0].y + V[1].y < K)
		ni = total - 1, nj = K;
	
	return { ni, nj };
}

int main()
{
	fasti;

	cin >> N >> K;

	tree.resize(N + 1);

	K++;

	for (ll i = 0, a, b; i < N - 1; i++)
	{
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	init();

	auto [ni, nj] = solve(1, -1);

	cout << ni;
}