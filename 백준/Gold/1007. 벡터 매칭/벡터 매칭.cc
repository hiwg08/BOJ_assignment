#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define f first
#define s second

using namespace std;

ll T, N, x, y, q;

ld Ans = LDBL_MAX;

bool Vis[21]{ 0 };

void solve(ll Idx, ll Cnt, vector<pll>& Comma)
{
	if (Cnt == N / 2)
	{
		vector<ll> L, R;

		x = 0, y = 0;

		for (ll i = 0; i < N; i++)
			Vis[i] ? L.push_back(i) : R.push_back(i);

		for (ll i = 0; i < N / 2; i++)
			x += Comma[R[i]].f - Comma[L[i]].f, y += Comma[R[i]].s - Comma[L[i]].s;

		Ans = min(Ans, (ld)sqrt((x * x) + (y * y)));

		return;
	}

	for (ll i = Idx; i < N; i++)
	{
		if (Vis[i]) continue;
		Vis[i] = true;
		solve(i + 1, Cnt + 1, Comma);
		Vis[i] = false;
	}
}

int main()
{
	fastio;

	cin >> T;

	while (T--)
	{
		cin >> N; 

		Ans = LDBL_MAX;

		vector<pll> Comma; Comma.resize(N);

		for (auto& iv : Comma)
			cin >> iv.f >> iv.s;

		solve(0, 0, Comma);

		cout.precision(6);

		cout << fixed << Ans << '\n';
	}
}