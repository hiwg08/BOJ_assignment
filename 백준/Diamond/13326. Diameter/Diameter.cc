#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, ini = LLONG_MIN;

vector<pll> V;

pll Q, W;

ld tot = LDBL_MAX;

ll stand[5001]{ 0 };

ll get_dist(pll a, pll b)
{
	return (((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
}

int main()
{
	cin >> N; V.resize(N);

	for (auto& iv : V)
		cin >> iv.x >> iv.y;

	for (ll i = 0; i < N; i++)
	{
		for (ll j = i + 1; j < N; j++)
		{
			if (get_dist(V[i], V[j]) > ini)
			{
				ini = get_dist(V[i], V[j]);
				Q = V[i];
			}
		}
	}

	sort(V.begin(), V.end(), [&](pll a, pll b) {
		return get_dist(Q, a) < get_dist(Q, b);
	});

	for (ll i = N - 2; i >= 0; i--)
	{
		stand[i] = stand[i + 1];

		for (ll j = i + 1; j < N; j++)
			stand[i] = max(stand[i], get_dist(V[i], V[j]));
	}

	ll maxi = 0;

	for (ll i = 0; i < N; i++)
	{
		for (ll j = i - 1; j >= 0; j--)
			maxi = max(maxi, get_dist(V[i], V[j]));

		tot = min(tot, (ld)(sqrt(stand[i + 1])) + (ld)(sqrt(maxi)));
	}

	cout.precision(3);

	cout << fixed << tot;
}