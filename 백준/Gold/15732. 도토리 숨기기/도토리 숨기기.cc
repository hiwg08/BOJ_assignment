#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, K, D, MAX = LLONG_MIN, MIN = LLONG_MAX;

vector<pair<pll, ll>> V;

ll get_dotori(ll standard)
{
	ll Cnt = 0;

	for (const auto &e : V)
	{
		ll tmp_x = e.x.x, tmp_y = e.x.y;

		if (tmp_x > standard)
			continue;
		if (tmp_y > standard)
			tmp_y = standard;

		Cnt += ((tmp_y - tmp_x) / e.y) + 1;
	}

	return Cnt;
}

void solve()
{
	ll lo = MIN, hi = MAX;

	while (lo + 1 < hi)
	{
		ll mid = (lo + hi) >> 1;

		if (get_dotori(mid) >= D)
			hi = mid;
		else
			lo = mid;
	}

	cout << hi << '\n';
}

int main()
{
	fastio;

	cin >> N >> K >> D;

	for (ll i = 0, a, b, c; i < K; i++)
	{
		cin >> a >> b >> c;
		MIN = min(MIN, a);
		MAX = max(MAX, b);
		V.push_back({ {a, b}, c });
	}

	solve();
}