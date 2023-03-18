#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

char Arr[9][9]{ 0 };

bool Vis[9][9][100]{ 0 };

int pre_block;

void move_down()
{
	pre_block = 0;

	for (int j = 0; j < 8; j++)
	{
		for (int i = 7; i >= 1; i--)
			Arr[i][j] = Arr[i - 1][j];
		Arr[0][j] = '.';
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Arr[i][j] == '#')
				pre_block++;
		}
	}
}

int dx[]{ 0, 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[]{ 0, 0, 1, 1, 1, 0, -1, -1, -1 };

bool solve(int px, int py)
{
	queue<pair<pii, int>> Q;

	Q.push({ {px, py}, 0 });

	Vis[px][py][0] = true;

	int pre_t = 0;

	while (!Q.empty())
	{
		pair<pii, int> T1 = Q.front();
		Q.pop();

		if (T1.y > pre_t)
		{
			pre_t = T1.y;
			move_down();
		}

		if (Arr[T1.x.x][T1.x.y] == '#')
			continue;

		if (pre_block == 0)
			return true;

		for (int dir = 0; dir < 9; dir++)
		{
			int nx = T1.x.x + dx[dir];
			int ny = T1.x.y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8)
				continue;

			if (Vis[nx][ny][T1.y + 1])
				continue;

			if (Arr[nx][ny] == '#')
				continue;

			Q.push({ {nx, ny}, T1.y + 1 });
		}
	}

	return false;
}

int main()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> Arr[i][j];

			if (Arr[i][j] == '#')
				pre_block++;
		}
	}

	cout << solve(7, 0) << '\n';
}