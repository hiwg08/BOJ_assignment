#include <bits/stdc++.h>

using namespace std;

int N, M, hole, val = INT_MAX, s_x, s_y;

bool vis[31][31]{ 0 };

char Arr[31][31]{ 0 };

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

bool check_monge(int nx, int ny)
{
	if (nx < 0 || ny < 0 || nx >= N || ny >= M)
		return false;
	else
	{
		if (vis[nx][ny] || Arr[nx][ny] == '*')
			return false;
	}

	return true;
}

void solve(int px, int py, int dir, int cnt, int rotate)
{
	vis[px][py] = true;

	int nx = px + dx[dir], ny = py + dy[dir];

	if (!check_monge(nx, ny)) // 다음 칸으로 이동하지 못 할때 --> 방향 틀어야됨
	{
		for (int i = 0; i < 4; i++)
		{
			if (i == dir)
				continue;

			int ni = px + dx[i], nj = py + dy[i];

			if (ni < 0 || nj < 0 || ni >= N || nj >= M)
				continue;

			if (vis[ni][nj])
				continue;

			if (Arr[ni][nj] == '*')
				continue;

			solve(ni, nj, i, cnt + 1, rotate + 1);
		}
	}
	else
		solve(nx, ny, dir, cnt + 1, rotate);

	if (cnt == hole)
		px == s_x && py == s_y ? val = 0 : val = min(val, rotate);

	vis[px][py] = false;
}

int main()
{
	int Idx = 0;

	while (true)
	{
		cin >> N >> M;

		if (cin.eof())
			break;

		hole = 0, val = INT_MAX;

		memset(vis, false, sizeof(vis));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> Arr[i][j];

				if (Arr[i][j] == '.')
					hole++;
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (Arr[i][j] == '.')
				{
					s_x = i, s_y = j;
					for (int k = 0; k < 4; k++)
						solve(i, j, k, 1, 1);
						
				}
			}
		}

		if (val == INT_MAX)
			val = -1;

		cout << "Case " << ++Idx << ": " << val << '\n';
	}
}
