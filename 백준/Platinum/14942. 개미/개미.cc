#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define f first
#define s second
#define MAX 100000

using namespace std;

ll N, Energy[MAX + 1]{ 0 }, Pre_Sum[MAX + 1]{ 0 }, Level[MAX + 1][17]{ 0 };

vector<pll> Tree[MAX + 1], V;

void DFS(ll Idx, ll Before, ll Sum, ll Depth)
{
	if (Idx != 1)
	{
		Level[Idx][0] = Before;
		V.push_back({ Idx, Depth });
	}
		
	for (auto e : Tree[Idx])
	{
		if (e.f == Before)
			continue;
		Pre_Sum[e.f] = Sum + e.s;
		DFS(e.f, Idx, Sum + e.s, Depth + 1);
	}
}

bool cmp(pll a, pll b)
{
	if (a.s == b.s)
		return a.f < b.f;
	return a.s < b.s;
}

void Init()
{
	sort(V.begin(), V.end(), cmp);

	for (auto e : V)
	{
		for (ll i = 1; i <= 16; i++)
			Level[e.f][i] = Level[Level[e.f][i - 1]][i - 1];
	}
}

void solve()
{
	for (ll i = 1; i <= N; i++)
	{
		ll Idx = i, tmp_E = Energy[Idx];
		
		for (ll j = 16; j >= 0; j--)
		{
			if (Level[Idx][j] != 0 && (tmp_E - (Pre_Sum[Idx] - Pre_Sum[Level[Idx][j]])) >= 0)
			{
				tmp_E -= (Pre_Sum[Idx] - Pre_Sum[Level[Idx][j]]);
				Idx = Level[Idx][j];
			}
		}

		cout << Idx << '\n';
	}
}

void Input()
{
	fastio;

	cin >> N;

	for (ll i = 1; i <= N; i++)
		cin >> Energy[i];

	for (ll i = 0, a, b, c; i < N - 1; i++)
	{
		cin >> a >> b >> c;
		Tree[a].push_back({ b, c });
		Tree[b].push_back({ a, c });
	}
}

int main()
{
	Input();

	DFS(1, -1, 0, 0);

	Init();

	solve();
}