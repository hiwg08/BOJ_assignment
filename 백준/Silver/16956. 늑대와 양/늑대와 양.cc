#include <bits/stdc++.h>

using namespace std;

int R, C;

char Arr[501][501]{ 0 };

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

bool check(int px, int py)
{
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = px + dx[dir], ny = py + dy[dir];

		if (nx < 0 || ny < 0 || nx >= R || ny >= C)
			continue;

		if (Arr[nx][ny] == 'S' || Arr[nx][ny] == 'D')
			continue;

		if (Arr[nx][ny] == 'W')
			return false;

		if (Arr[nx][ny] == '.')
			Arr[nx][ny] = 'D';
	}

	return true;
}

int main()
{
	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cin >> Arr[i][j];
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (Arr[i][j] == 'S')
			{
				if (!check(i, j))
				{
					cout << 0 << '\n';
					exit(0);
				}
			}
		}
	}

	cout << 1 << '\n';

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << Arr[i][j];
		cout << '\n';
	}
}