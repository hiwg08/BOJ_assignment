#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, K, total;

vector<pll> V;

vector<ll> bag;

priority_queue<ll, vector<ll>, greater<ll>> PQ;

bool cmp(pll a, pll b)
{
	return a.x > b.x;
}

int main()
{
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
			PQ.push(V[i].y);
			PQ.pop();
		} // 여기서부터는 자유
		else
		{
			PQ.push(V[i].y);
			
			if (bag[bag_point] >= V[i].x)
				bag_point++;

			else
				PQ.pop();
		}
	}

	while (!PQ.empty())
	{
		total += PQ.top();
		PQ.pop();
	}

	cout << total << '\n';
}