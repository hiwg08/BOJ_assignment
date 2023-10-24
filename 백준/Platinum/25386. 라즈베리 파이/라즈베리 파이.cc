#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, M, tot;

bool exist[300001]{ 0 };

ll en = -1, sta = -1;

vector<pll> V;

ll calc(ll Id)
{
	ll ret = -1;

	if (V[Id].x >= V[Id].y)
		ret = (V[Id].x - V[Id].y);
	else
		ret = (V[Id].x + N - V[Id].y);

	return ret;
}

bool covered(ll p)
{
	if (sta > en)
	{
		if (p <= N && p >= sta + 1)
			return true;

		if (p >= 1 && p <= en)
			return true;
	}
	else
	{
		if (sta + 1 <= p && p <= en - 1)
			return true;
	}

	return false;
}

void for_sweep()
{
	vector<pair<pll, ll>> midv;

	for (ll i = 0; i < M; i++)
	{
		if (V[i].x < V[i].y)
			midv.push_back({ { V[i].y, N + V[i].x }, i });
		else
		{
			midv.push_back({ { V[i].y, V[i].x }, i });
			midv.push_back({ { N + V[i].y, N + V[i].x }, i });
		}
	}

	sort(midv.begin(), midv.end(), [&](pair<pll, ll> a, pair<pll, ll> b){
		if (a.x.x == b.x.x)
			return a.x.y > b.x.y;
		return a.x.x < b.x.x;
	});

	memset(exist, 0, sizeof(exist));

	ll hi = midv[0].x.y;

	for (ll i = 1; i < (ll)midv.size(); i++)
	{
		if (hi > midv[i].x.y)
			exist[midv[i].y] = true;
		else
			hi = midv[i].x.y;
	}
}

int main()
{
	fastio;

	cin >> N >> M; V.resize(M);

	for (ll i = 0; i < M; i++)
		cin >> V[i].x;

	for (ll i = 0; i < M; i++)
		cin >> V[i].y;

	sort(V.begin(), V.end());

	for (ll i = 0; i < M; i++)
	{
		if (exist[V[i].y])
		{
			cout << -1;
			exit(0);
		}
		exist[V[i].y] = true;
	}

	if (N == M)
	{
		for (ll i = 0; i < M; i++)
		{
			if (V[i].x != V[i].y)
			{
				cout << -1;
				exit(0);
			}
		}

		cout << 0;
		exit(0);
	}

	en = V[0].y, sta = V[1].y;

	for (ll i = 2; i < M; i++)
	{
		if (!covered(V[i].y))
		{
			cout << -1;
			exit(0);
		}

		sta = V[i].y;
	}

	for_sweep();

	for (ll i = 0; i < M; i++)
	{
		if (exist[i])
			tot += N + calc(i);
		else
			tot += calc(i);
	}
	
	cout << tot;
}