#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int T;

int N, M;

bool cmp(pii a, pii b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

bool Vis[1001]{ 0 };

int main()
{
	fastio;

	cin >> T;

	while (T--)
	{
		cin >> N >> M;

		int Ans = 0;
		
		memset(Vis, false, sizeof(Vis));

		vector<pii> V; V.resize(M);

		for (auto& iv : V)
			cin >> iv.x >> iv.y;

		sort(V.begin(), V.end(), cmp);

		for (int i = 0; i < M; i++)
		{
			for (int j = V[i].x; j <= V[i].y; j++)
			{
				if (Vis[j])
					continue;
				Vis[j] = true;
				Ans++;
				break;
			}
		}

		cout << Ans << '\n';
	}
}