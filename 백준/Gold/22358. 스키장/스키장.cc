#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, M, K, S, T;

vector<pll> Tree[100001];

ll DP[100001][11]{ 0 };

ll solve(ll pos, ll lift)
{
	if (pos == T && lift == K)
		return 0;

	ll& ret = DP[pos][lift];

	if (ret != -1)
		return ret;

	ret = LLONG_MIN;

	for (auto e : Tree[pos])
	{
		if (pos > e.x && lift < K)
		{
			ll T1 = solve(e.x, lift + 1);

			if (T1 == LLONG_MIN)
				continue;

			ret = max(ret, T1);
		}

		else if (pos < e.x)
		{
			ll T2 = solve(e.x, lift);

			if (T2 == LLONG_MIN)
				continue;

			ret = max(ret, T2 + e.y);
		}
	} 

	return ret;
}

int main()
{
	fastio;

	cin >> N >> M >> K >> S >> T;

	for (ll i = 0, a, b, c; i < M; i++)
	{
		cin >> a >> b >> c;
		Tree[a].push_back({ b, c });
		Tree[b].push_back({ a, c });
	}

	memset(DP, -1, sizeof(DP));

	ll ans = solve(S, 0);

	if (ans == LLONG_MIN)
		ans = -1;

	cout << ans;
}