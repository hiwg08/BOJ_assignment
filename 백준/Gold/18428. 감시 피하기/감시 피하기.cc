#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int N;

bool Ans = false;

char Board[7][7]{ 0 };

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

vector<pii> Teacher;

void solve(int x, int y, int Cnt)
{
	if (Cnt == 3)
	{
		for (auto e : Teacher)
		{
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = e.first, ny = e.second;

				while (nx >= 0 && ny >= 0 && nx < N && ny < N)
				{
					nx += dx[dir];
					ny += dy[dir];

					if (Board[nx][ny] == 'O' || Board[nx][ny] == 'T') break;
					if (Board[nx][ny] == 'S') return;
				}
			}
		}

		Ans = true;
		return;
	}
	while (x < N)
	{
		while (y < N)
		{
			if (Board[x][y] == 'X')
			{
				Board[x][y] = 'O';
				solve(x, y + 1, Cnt + 1);
				Board[x][y] = 'X';
			}
			y++;
		}
		y = 0;
		x++;
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Board[i][j];
			if (Board[i][j] == 'T') Teacher.push_back({ i, j });
		}
	}

	solve(0, 0, 0);

	Ans ? cout << "YES" << '\n' : cout << "NO" << '\n';
}