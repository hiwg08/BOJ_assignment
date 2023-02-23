#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll ,ll>
#define f first
#define s second

using namespace std;

vector<vector<pll>> Tree;

vector<pll> V;

ll N, M, Prefix_SUM[40001]{ 0 }, Depth[40001]{ 0 }, Parent[40001][17]{ 0 };

void DFS(ll Idx, ll Before, ll Cnt, ll Sum)
{
	if (Before != 0)
	{
		Prefix_SUM[Idx] = Sum;
		Parent[Idx][0] = Before;
		Depth[Idx] = Cnt;
	}

	V.push_back({ Depth[Idx], Idx });

	for (ll i = 0; i < (ll)Tree[Idx].size(); i++)
	{
		if (Tree[Idx][i].f == Before)
			continue;
		DFS(Tree[Idx][i].f, Idx, Cnt + 1, Sum + Tree[Idx][i].s);
	}
}

void Init()
{
	for (pll e : V)
	{
		for (ll i = 1; i <= 16; i++)
			Parent[e.s][i] = Parent[Parent[e.s][i - 1]][i - 1];
	}
}

ll Distance(ll a, ll b)
{
	ll Ans = 0;

	if (Depth[a] < Depth[b])
		swap(a, b);

	for (ll i = 16; i >= 0; i--)
	{
		if (Depth[a] - Depth[b] >= (static_cast<ll>(1) << i))
		{
			Ans += abs(Prefix_SUM[Parent[a][i]] - Prefix_SUM[a]);
			a = Parent[a][i];
		}
	}

	if (a == b)
		return Ans;

	for (ll i = 16; i >= 0; i--)
	{
		if (Parent[a][i] != Parent[b][i])
		{
			Ans += (abs(Prefix_SUM[Parent[a][i]] - Prefix_SUM[a]) + abs(Prefix_SUM[Parent[b][i]] - Prefix_SUM[b]));
			a = Parent[a][i];
			b = Parent[b][i];
		}
	}

	Ans += (abs(Prefix_SUM[Parent[a][0]] - Prefix_SUM[a]) + abs(Prefix_SUM[Parent[b][0]] - Prefix_SUM[b]));

	return Ans;
}

int main()
{
	fastio;

	cin >> N;

	Tree.resize(N + 1);

	for (ll i = 0; i < N - 1; i++)
	{
		ll a, b, c; cin >> a >> b >> c;
		Tree[a].push_back({ b, c });
		Tree[b].push_back({ a, c });
	}

	DFS(1, 0, 0, 0);

	sort(V.begin(), V.end());

	Init();

	cin >> M;

	for (ll i = 0; i < M; i++)
	{
		ll a, b; cin >> a >> b;

		cout << Distance(a, b) << '\n';
	}
}