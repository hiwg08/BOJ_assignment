#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

multiset<ll> ms;

vector<pll> V;

ll N, K, total, Idx;

int main()
{
	cin >> N >> K; V.resize(N);

	for (auto& iv : V)
		cin >> iv.x >> iv.y;

	sort(V.begin(), V.end(), [&](pll a, pll b) {
		if (a.y == b.y)
			return a.x < b.x;
		return a.y < b.y;
	});

	for (ll i = 1; i < K; i++)
		ms.insert(0);

	for (ll i = 0; i < N; i++)
	{
		ll ni = V[i].x, nj = V[i].y;

		if (V[i].x <= Idx)
			continue;

		multiset<ll>::iterator it = ms.lower_bound(ni);

		if ((ll)ms.size() >= 1)
			it--;

		if (it == ms.end() || (*it) >= ni)
		{
			total++;
			Idx = nj;
		}
		else
		{
			ms.erase(it);
			ms.insert(nj);
		}
	}
	cout << total;
}