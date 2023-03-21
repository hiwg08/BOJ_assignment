#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N;

char Map[2001][2001]{ 0 };

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

bool Vis[2001][2001]{ 0 };

void wide_range(int px, int py)
{
	for (int dir = 0; dir < 4; dir++)
	{
		int rx = px, ry = py;

		while (true)
		{
			rx += dx[dir], ry += dy[dir];

			if (rx < 0 || ry < 0 || rx >= N || ry >= N)
				break;

			if (Map[rx][ry] == 'O' || Map[rx][ry] == 'X')
				break;

			Vis[rx][ry] = true;
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> Map[i][j];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Map[i][j] == 'O')
				wide_range(i, j);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Map[i][j] == '.')
				Vis[i][j] ? cout << '.' : cout << 'B';
			else
				cout << Map[i][j];
		}
		cout << '\n';
	}
}