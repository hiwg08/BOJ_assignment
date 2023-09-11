#include <bits/stdc++.h>
#define ll long long
#define MAX (ll)(2147483647)

using namespace std;

ll N;

vector<tuple<ll, ll, ll>> V;

bool check(ll standard)
{
	ll total = 0;

	for (ll i = 0; i < N; i++)
	{
		auto& [ni, nj, nk] = V[i];

		ll Q = min(standard, nj);

		if (ni <= Q && Q <= nj)
			total += ((Q - ni) / nk) + 1;
	}

	return total & 1;
}

ll solve()
{
	ll lo = 0, hi = MAX;

	while (lo + 1 < hi)
	{
		ll mid = (lo + hi) >> 1;

		check(mid) ? hi = mid : lo = mid;
	}

	return hi;
}

int main()
{
	cin >> N; V.resize(N);

	ll tot = 0;

	for (ll i = 0, a, b, c; i < N; i++)
	{
		cin >> a >> b >> c;
		auto& [ni, nj, nk] = V[i];
		ni = a, nj = b, nk = c;

		tot += ((nj - ni) / nk) + 1;
	}

	if (!(tot & 1))
	{
		cout << "NOTHING";
		exit(0);
	}

	ll ans = solve();

	ll cnt = 0;

	for (ll i = 0; i < N; i++)
	{
		auto& [ni, nj, nk] = V[i];

		if (ni <= ans && ans <= nj)
		{
			if ((ans - ni) % nk == 0)
				cnt++;
		}
	}

	cout << ans << " " << cnt;
}