#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define f first
#define s second

using namespace std;

ll N, M, D[100001]{ 0 }, P[100001][18]{ 0 }, SUM[100001]{ 0 }, Order[100001]{ 0 };

vector<vector<pll>> Tree;

vector<pll> V;

void DFS(ll Idx, ll Before, ll Cnt, ll S)
{
	P[Idx][0] = Before;
	D[Idx] = Cnt;
	SUM[Idx] = S;

	V.push_back({ D[Idx], Idx });

	for (ll i = 0; i < (ll)Tree[Idx].size(); i++)
	{
		if (Tree[Idx][i].f == Before)
			continue;
		Order[Tree[Idx][i].f] = i + 1;
		DFS(Tree[Idx][i].f, Idx, Cnt + 1, S + Tree[Idx][i].s);
	}
}

void Init()
{
	for (pll e : V)
	{
		for (ll i = 1; i <= 17; i++)
			P[e.s][i] = P[P[e.s][i - 1]][i - 1];
	}
}

ll solve(ll Start, ll Interval)
{
	ll ret = Start;

	for (ll i = 17; i >= 0; i--)
	{
		if (Interval >= ((ll)1 << i))
		{
			ret = P[ret][i];
			Interval -= ((ll)1 << i);
		}
	}

	return ret;
}

ll Query(ll L, ll R, ll K)
{
	ll Ans = 0;

	ll O_L = L, O_R = R;

	bool CHK = false;

	if (D[L] < D[R])
	{
		CHK = true;
		for (ll i = 17; i >= 0; i--)
		{
			if (D[R] - D[L] >= ((ll)1 << i))
			{
				Ans += abs(SUM[P[R][i]] - SUM[R]);
				R = P[R][i];
			}
		}
	}
	else
	{
		for (ll i = 17; i >= 0; i--)
		{
			if (D[L] - D[R] >= ((ll)1 << i))
			{
				Ans += abs(SUM[P[L][i]] - SUM[L]);
				L = P[L][i];
			}
		}
	}
	
	if (L == R)
	{
		if (K == -1)
			return Ans;
		
		if (CHK)
			return solve(O_R, D[O_R] - D[R] - K);
		return solve(O_L, K);
	}

	for (ll i = 17; i >= 0; i--)
	{
		if (P[L][i] != P[R][i])
		{
			Ans += (abs(SUM[P[L][i]] - SUM[L]) + abs(SUM[P[R][i]] - SUM[R]));
			L = P[L][i];
			R = P[R][i];
		}
	}

	Ans += (abs(SUM[P[L][0]] - SUM[L]) + abs(SUM[P[R][0]] - SUM[R]));

	if (K == -1)
		return Ans;

	ll D_F = D[O_L] - D[P[L][0]], D_S = D[O_R] - D[P[R][0]];

	if (K < D_F)
		return solve(O_L, K);
	return solve(O_R, D_F + D_S - K);
}

int main()
{
	fastio;

	cin >> N;

	Tree.resize(N + 1);

	for (ll i = 0; i < N - 1; i++)
	{
		ll u, v, w; cin >> u >> v >> w;
		Tree[u].push_back({ v, w });
		Tree[v].push_back({ u, w });
	}

	DFS(1, 0, 0, 0);

	sort(V.begin(), V.end());

	Init();

	cin >> M;

	for (ll i = 0; i < M; i++)
	{
		ll u, v, k; cin >> u >> v >> k;
		if (u == 1)
			cout << Query(v, k, -1) << '\n';
		else
		{
			ll d; cin >> d;
			cout << Query(v, k, d - 1) << '\n';
		}
	}
}