#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, K, total;

vector<pll> V;

vector<ll> bag;

multiset<ll> ms;

bool cmp(pll a, pll b)
{
	return a.x > b.x;
}

int main() // greedy, data structure, sorting
{
	fastio;

	cin >> N >> K; V.resize(N); bag.resize(K);

	for (auto& iv : V)
		cin >> iv.x >> iv.y;

	for (auto& iv : bag)
		cin >> iv;

	sort(V.begin(), V.end(), cmp);

	sort(bag.begin(), bag.end(), greater<ll>());

	ll bag_point = 0;

	for (ll i = 0; i < (ll)V.size(); i++)
	{
		if (bag_point >= (ll)bag.size())
		{
			ms.insert(V[i].y);
			ms.erase(ms.begin());
		}
		else
		{
			ms.insert(V[i].y);
			
			if (bag[bag_point] >= V[i].x)
				bag_point++;
			else
				ms.erase(ms.begin());
		}
	}

	for (auto e : ms)
		total += e;

	cout << total << '\n';
}