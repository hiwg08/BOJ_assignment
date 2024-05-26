#include <bits/stdc++.h>

using namespace std;

int N, M;

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

int board[1001][1001]{ 0 };

int cnt[2]{ 0 };

bool solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M)
					continue;

				if (board[i][j] == board[nx][ny])
					return true;
			}
		}
	}

	return false;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			cnt[board[i][j]]++;
		}
	}

	if (cnt[0] % 2 != 0 || cnt[1] % 2 != 0)
	{
		cout << -1;
		exit(0);
	}

	if (solve())
		cout << 1;
	else
		cout << -1;
}