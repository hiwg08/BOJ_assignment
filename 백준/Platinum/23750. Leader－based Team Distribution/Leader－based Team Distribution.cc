#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, M, total;

vector<pll> V;

priority_queue<pll> PQ;

ll team[300001]{ 0 };

int main()
{
	fastio;

	cin >> N >> M; V.resize(N);

	for (auto& iv : V)
		cin >> iv.x >> iv.y;

	for (ll i = 0; i < M; i++)
		cin >> team[i];

	sort(V.begin(), V.end());
	sort(team, team + M);

	PQ.push({ V.back().y, V.back().x });

	ll Idx = (ll)V.size() - 2;

	for (ll i = M - 1; i >= 0; i--)
	{
		total += PQ.top().x;
		PQ.pop();

		if (i == 0)
			break;

		for (ll j = 0; j < team[i]; j++)
		{
			PQ.push({ V[Idx].y, V[Idx].x });
			Idx--;
		}
	}

	cout << total;
}