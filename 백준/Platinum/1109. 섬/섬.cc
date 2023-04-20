#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N, M, cnt, ori;

char Arr[51][51]{ 0 };

int vis[51][51]{ 0 };

int ans[3001]{ 0 };

vector<pii> start[3000];

int ano_vis[3001]{ 0 };

int dx[]{ 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[]{ 0, 1, 0, -1, 1, 1, -1, -1 };

vector<int> V[3001];

int dfs(int Idx)
{
	ano_vis[Idx] = true;
	
	int ma = 0;

	for (int i = 0; i < (int)V[Idx].size(); i++) 
	{
		int T1 = dfs(V[Idx][i]);

		ma = max(ma, T1);
	}

	if (ans[ma] == -1)
		ans[ma] = 0;

	ans[ma]++;

	return ma + 1;
}

void bfs(int px, int py, char c, int num)
{
	vis[px][py] = cnt;

	if (cnt > 0)
		start[cnt].push_back({ px, py });

	queue<pii> Q;

	Q.push({ px, py });

	while (!Q.empty())
	{
		pii T1 = Q.front();
		Q.pop();

		for (int dir = 0; dir < num; dir++)
		{
			int nx = T1.x + dx[dir];
			int ny = T1.y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;

			if (vis[nx][ny] >= 1 || vis[nx][ny] < 0)
				continue;

			if (Arr[nx][ny] != c)
				continue;

			vis[nx][ny] = cnt;

			if (cnt > 0)
				start[cnt].push_back({ nx, ny });

			Q.push({ nx, ny });
		}
	}
}

set<int> make_sima(int px, int py, int standard)
{
	set<int> s;

	vis[px][py] = cnt;

	queue<pii> Q;

	Q.push({ px, py });

	while (!Q.empty())
	{
		pii T1 = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = T1.x + dx[dir];
			int ny = T1.y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;

			if (vis[nx][ny] == standard || vis[nx][ny] < 0)
				continue;

			if (vis[nx][ny] != standard && vis[nx][ny] > 0)
				s.insert(vis[nx][ny]);

			if (Arr[nx][ny] != '.')
				continue;

			vis[nx][ny] = cnt;

			Q.push({ nx, ny });
		}
	}

	return s;
}

void is_cycle(int num)
{
	for (int i = 0; i < (int)start[num].size(); i++)
	{
		int ni = start[num][i].x, nj = start[num][i].y;

		for (int dir = 0; dir < 8; dir++)
		{
			int nx = ni + dx[dir], ny = nj + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;

			if (vis[nx][ny] == 0) // 이건 확실히 둘러쌓인 곳.
			{
				set<int> q = make_sima(nx, ny, num);

				for (auto e : q)
					V[num].push_back(e);
			}
		}
	}
}

void input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> Arr[i][j];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!vis[i][j] && Arr[i][j] == 'x')
			{
				cnt++;
				bfs(i, j, 'x', 8);
			}
		}
	}

	ori = cnt;

	cnt = -9999;

	// N, M

	for (int i = 0; i < M; i++)
	{
		if (!vis[0][i] && Arr[0][i] == '.')
			bfs(0, i, '.', 4);
		if (!vis[N - 1][i] && Arr[N - 1][i] == '.')
			bfs(N - 1, i, '.', 4);
	}

	for (int i = 0; i < N; i++)
	{
		if (!vis[i][0] && Arr[i][0] == '.')
			bfs(i, 0, '.', 4);
		if (!vis[i][M - 1] && Arr[i][M - 1] == '.')
			bfs(i, M - 1, '.', 4);
	}
}

int main()
{
	input();

	for (int i = 1; i <= ori; i++)
		is_cycle(i);

	if (ori == 0)
	{
		cout << -1;
		exit(0);
	}
		
	int maxi = 0;

	memset(ans, -1, sizeof(ans));

	for (int i = 1; i <= ori; i++)
	{
		if (!ano_vis[i])
			maxi = max(maxi, dfs(i));
	}

	for (int i = 0; i < 3000; i++)
	{
		if (ans[i] == -1)
			break;
		cout << ans[i] << " ";
	}
}