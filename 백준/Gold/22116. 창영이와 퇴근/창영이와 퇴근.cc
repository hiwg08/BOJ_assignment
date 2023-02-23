#include <bits/stdc++.h>
#define pii pair<int, int>
#define MAX 1000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, Board[1001][1001]{ 0 };

bool Vis[1001][1001]{ 0 };

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

bool BFS(int mid)
{
	memset(Vis, false, sizeof(Vis));

	queue<pii> Q;

	Q.push({ 0, 0 });

	Vis[0][0] = true;

	while (!Q.empty())
	{
		pii st1 = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{	
			int nx = st1.first + dx[dir];
			int ny = st1.second + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;

			if (Vis[nx][ny])
				continue;

			if (abs(Board[st1.first][st1.second] - Board[nx][ny]) > mid)
				continue;

			Vis[nx][ny] = true;
			Q.push({ nx, ny });
		}
	}

	return Vis[N - 1][N - 1];
}

int Binary_Search()
{
	int lo = -1, hi = MAX - 1;

	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;

		if (BFS(mid))
			hi = mid;
		else
			lo = mid;
	}

	return hi;
}

int main()
{
	fastio;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> Board[i][j];
	}

	cout << Binary_Search() << '\n';
}