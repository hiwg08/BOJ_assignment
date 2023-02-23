#include <bits/stdc++.h>

using namespace std;

int N, M, MAX = -1;

int Board[10][10]{ 0 };

void solve()
{
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < M; y++)
		{
			for (int tx = 0; tx < N; tx++)
			{
				for (int ty = 0; ty < M; ty++)
				{
					int Interval_x = tx - x, Interval_y = ty - y;
					int nx = x, ny = y;
					int tmp_I = 0;

					while (true)
					{
						if (tmp_I == 0)
							tmp_I = Board[nx][ny];
						else
							tmp_I *= 10, tmp_I += Board[nx][ny];

						int sq_r = (int)sqrt(tmp_I);

						if (sq_r * sq_r == tmp_I)
							MAX = max(MAX, tmp_I);

						nx += Interval_x, ny += Interval_y;

						if (x == tx && y == ty)
							break;
						if (nx < 0 || ny < 0 || nx >= N || ny >= M)
							break;
					}
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string S; cin >> S;

		for (int j = 0; j < M; j++)
			Board[i][j] = (int)(S[j] - '0');
	}

	solve();

	cout << MAX << '\n';
}