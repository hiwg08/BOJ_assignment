#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N, M, fir, sec, thi;

int Arr[51][51]{ 0 };

int cnt = 0;

bool Vis[51][51]{ 0 };

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

int sagi[51][51]{ 0 };

int dist[2501]{ 0 };

void bfs(int px, int py)
{
	int monge = 0;

	Vis[px][py] = true;

	queue<pii> Q;

	Q.push({px, py});

	while (!Q.empty())
	{
		auto T1 = Q.front();
		Q.pop();
		monge++;

		int val = Arr[T1.x][T1.y];

		sagi[T1.x][T1.y] = cnt;

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = T1.x + dx[dir], ny = T1.y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;

			if ((val & (1 << (3 - dir))) != 0) // 벽이 있으면 스킵
				continue;

			if (Vis[nx][ny])
				continue;

			Vis[nx][ny] = true;

			Q.push({nx, ny});
		}
	}

	sec = max(sec, monge);

	dist[cnt] = monge;
}

int main()
{
	cin >> N >> M;

	swap(N, M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> Arr[i][j];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!Vis[i][j])
			{
				cnt++;
				bfs(i, j);
			}
		}
	}

	fir = cnt; // 방의 개수

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = i + dx[dir], ny = j + dy[dir];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M)
					continue;

				if (sagi[nx][ny] != sagi[i][j])
					thi = max(thi, dist[sagi[nx][ny]] + dist[sagi[i][j]]);
			}
		}
	}

	cout << fir << '\n' << sec << '\n' << thi;
}