#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N, K;

vector<pii> V;

bool Vis[1001]{ 0 };

int calc(int x1, int y1, int x2, int y2)
{
	double dist = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
	
	if (dist - (int)dist > 0)
		return (int)(dist / 10) + 1;
	return (int)(dist / 10);	
}

bool bfs(int params)
{
	memset(Vis, false, sizeof(Vis));

	queue<pair<pii, int>> Q;

	Q.push({ {0, 0}, 0 });

	Vis[0] = true; // 시작점이 0이다.

	while (!Q.empty())
	{
		auto T1 = Q.front();
		Q.pop();

		if (T1.y >= K + 1)
			continue;

		int ni = T1.x.x, nj = T1.x.y;

		for (int dir = 0; dir <= N + 1; dir++)
		{
			if (Vis[dir])
				continue;

			if (calc(ni, nj, V[dir].x, V[dir].y) > params)
				continue;

			else
			{
				if (V[dir].x == 10000 && V[dir].y == 10000 && T1.y + 1 <= K + 1)
					return true;

				Vis[dir] = true;
				Q.push({ {V[dir].x, V[dir].y}, T1.y + 1});
			}
		}
	}

	return false;


}

int solve()
{
	int lo = 0, hi = calc(0, 0, 10000, 10000);

	while (lo + 1 < hi)
	{
		int mid = (lo + hi) >> 1;

		bfs(mid) ? hi = mid : lo = mid;
	}

	return hi;
}

int main()
{
	cin >> N >> K;

	V.push_back({ 0, 0 });

	for (int i = 0, a, b; i < N; i++)
	{
		cin >> a >> b;
		V.push_back({ a, b });
	}

	V.push_back({ 10000, 10000 });

	cout << solve();
}