#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, M, total;

vector<pll> V;

vector<pll> tmp;

multiset<pll> ms;

bool cmp(pll a, pll b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

int main()
{
	fastio;

	cin >> N >> M; V.resize(N); tmp.resize(M);

	for (auto& iv : V)
		cin >> iv.x >> iv.y;

	for (auto& iv : tmp)
		cin >> iv.x >> iv.y;

	sort(V.begin(), V.end(), cmp);

	sort(tmp.begin(), tmp.end());

	ll fir = -1, sum = 0;

	for (ll i = 0; i < M; i++)
	{
		if (fir != tmp[i].x)
		{
			if (fir != -1)
				ms.insert({ fir, sum });
			fir = tmp[i].x;
			sum = tmp[i].y;
		}
		else
			sum += tmp[i].y;
	}

	if (sum != 0)
		ms.insert({ fir, sum });

	for (ll i = 0; i < N; i++)
	{
		auto it = ms.lower_bound(make_pair(V[i].x, (ll)-987654321));

		if (it == ms.end())
			continue;

		if ((*it).x > V[i].y)
			continue;

		auto ni = (*it).x, nj = (*it).y;

		ms.erase(it);

		if (nj - 1 >= 1)
			ms.insert({ ni, nj - 1 });

		total++;
	}

	cout << total;
}