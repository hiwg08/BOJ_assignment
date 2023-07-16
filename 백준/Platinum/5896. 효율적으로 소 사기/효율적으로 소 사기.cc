#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

vector<pll> V;

ll N, K, M, cnt;

bool cmp(pll a, pll b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

struct comp
{
	bool operator()(pll a, pll b)
	{
		return a.x > b.x;
	}
};

priority_queue<pll, vector<pll>, comp> diff; // 민 힙

priority_queue<ll> ori;

int main()
{
	cin >> N >> K >> M; V.resize(N);

	for (auto& iv : V)
		cin >> iv.x >> iv.y;

	sort(V.begin(), V.end(), cmp);

	for (ll i = 0; i < K; i++)
	{
		if (M >= V[i].y)
		{
			cnt++;
			M -= V[i].y;
			diff.push({ V[i].x - V[i].y, i });
		}
		else
		{
			cout << cnt;
			exit(0);
		}
	}

	for (ll i = K; i < N; i++)
	{
		ll fir = V[i].x, sec = LLONG_MAX;

		if (!diff.empty())
			sec = diff.top().x + V[i].y;

		if (fir < sec && M - fir >= 0)
		{
			M -= fir;
			cnt++;
			ori.push(fir);
			continue;
		}
		if (sec != LLONG_MAX && sec <= fir && M - sec >= 0)
		{
			M -= sec;
			cnt++;
			ori.push(V[diff.top().y].x);
			diff.pop();
			diff.push({ V[i].x - V[i].y, i });
			continue;
		}

		if (!ori.empty() && ori.top() > V[i].x)
		{
			M = M + ori.top() - V[i].x;
			ori.pop();
		}
	}

	cout << cnt;
}