#include <bits/stdc++.h>
#define int long long

using namespace std;

int N, M, K, Ans, Init[11][11]{ 0 }, Board[11][11]{ 0 };

deque<int> Tree[11][11], Dead[11][11];

int dx[]{ 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[]{ 0, 1, 1, 1, 0, -1, -1, -1 };

void spring()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int Idx = 0;

			while (!Tree[i][j].empty() && Idx < (int)Tree[i][j].size() && Board[i][j] >= Tree[i][j][Idx])
			{
				Board[i][j] -= Tree[i][j][Idx];
				Tree[i][j][Idx] += 1;
				Idx++;
			}

			int remove = (int)Tree[i][j].size() - Idx;

			while (!Tree[i][j].empty() && remove > 0)
			{
				Dead[i][j].push_back(Tree[i][j].back());
				Tree[i][j].pop_back();
				remove--;
			}
		}
	}
}
void summer()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			while (!Dead[i][j].empty())
			{
				Board[i][j] += Dead[i][j].back() / 2;
				Dead[i][j].pop_back();
			}
		}
	}
}

void rewind(int x, int y)
{
	for (int dir = 0; dir < 8; dir++)
	{
		int nx = x + dx[dir], ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			continue;
		Tree[nx][ny].push_front(1);
	}
}

void fall()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < (int)Tree[i][j].size(); k++)
			{
				if (Tree[i][j][k] % 5 == 0)
					rewind(i, j);
			}
		}
	}
}
void winter()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			Board[i][j] += Init[i][j];
	}
}

int32_t main()
{
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Init[i][j];
			Board[i][j] = 5;
		}
	}

	for (int i = 0, a, b, c; i < M; i++)
	{
		cin >> a >> b >> c;
		a--, b--;
		Tree[a][b].push_back(c);
	}

	for (int i = 0; i < K; i++)
	{
		spring();
		summer();
		fall();
		winter();
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			Ans += (int)Tree[i][j].size();
	}

	cout << Ans << '\n';
}