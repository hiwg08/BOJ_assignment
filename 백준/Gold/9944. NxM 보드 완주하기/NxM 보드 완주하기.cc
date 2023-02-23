#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, M, hole, val = INT_MAX;

char Arr[31][31]{ 0 };

int Vis[31][31]{ 0 };

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

void solve(int x, int y, int move, int total)
{
	int cnt = 0;

	if (Vis[x][y] == 0)
		cnt++;

	if (total + cnt == hole)
	{
		val = min(val, move);
		return;
	}

	Vis[x][y]++;

	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x, ny = y;

		while (true)
		{
			nx += dx[dir], ny += dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				break;
			if (Arr[nx][ny] == '*')
				break;
			if (Vis[nx][ny] >= 1)
				break;
			Vis[nx][ny]++;
			cnt++;
		}

		nx -= dx[dir], ny -= dy[dir];

		if (nx != x || ny != y)
			solve(nx, ny, move + 1, total + cnt);

		while (true)
		{
			if (nx == x && ny == y)
				break;
			Vis[nx][ny]--, cnt--;
			nx -= dx[dir], ny -= dy[dir];
		}
	}

	Vis[x][y]--;
}

void Input()
{
	cin >> N >> M;

	if (cin.eof())
		exit(0);

	memset(Arr, 0, sizeof(Arr));

	memset(Vis, 0, sizeof(Vis));

	hole = 0, val = INT_MAX;

	for (int i = 0; i < N; i++)
	{
		string S; cin >> S;

		for (int j = 0; j < M; j++)
		{
			Arr[i][j] = S[j];
			if (S[j] == '.') hole++;
		}
	}
}

int main()
{
	fastio;

	int Idx = 0;

	while (true)
	{
		Input();

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (Arr[i][j] == '.')
					solve(i, j, 0, 0);
			}
		}

		cout << "Case " << ++Idx << ": ";

		val == INT_MAX ? cout << -1 << '\n' : cout << val << '\n';
	}
}