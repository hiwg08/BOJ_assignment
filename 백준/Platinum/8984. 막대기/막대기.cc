#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, L, DP[100001][3]{ 0 }, Ans = LLONG_MIN;

vector<pll> V;

bool cmp(pll a, pll b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

ll solve(ll Idx, ll cond)
{
	ll& ret = DP[Idx][cond];

	if (ret != -1)
		return ret;

	ret = abs(V[Idx].x - V[Idx].y) + L;

	for (ll i = Idx + 1; i < N; i++)
	{
		if (V[Idx].y == V[i].y && cond == 2)
			ret = max(ret, (abs(V[Idx].x - V[Idx].y) + L) + solve(i, 1));

		if (V[Idx].x == V[i].x && cond == 1)
			ret = max(ret, (abs(V[Idx].x - V[Idx].y) + L) + solve(i, 2));
	}

	return ret;
}

int main()
{
	fastio;

	cin >> N >> L; V.resize(N);

	for (auto& iv : V)
		cin >> iv.x >> iv.y;
	
	sort(V.begin(), V.end(), cmp);

	memset(DP, -1, sizeof(DP));

	for (ll i = 0; i < N; i++)
		Ans = max({ Ans, solve(i, 1), solve(i, 2) });

	cout << Ans << '\n';
}