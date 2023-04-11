#include <bits/stdc++.h>

using namespace std;

int N, M, H;

bool able[41][41]{ 0 };

bool dir[41][41][41]{ 0 };

bool move_f(int garo)
{
	int fir = garo, hi = 0;

	while (hi <= H)
	{
		int nxt = hi + 1;

		if (dir[fir][nxt][fir + 1])
			fir++;
		else if (dir[fir][nxt][fir - 1])
			fir--;

		hi++;
	}

	return fir == garo;
}

void solve(int x, int y, int select, int origin)
{
	if (select == 0) // 이 때 사다리 건너기
	{
		for (int i = 1; i <= N; i++)
		{
			if (!move_f(i))
				return;
		}
		cout << origin;
		exit(0);
	}

	if (x >= N)
		return;

	if (able[x][y] || able[x + 1][y])
	{
		if (y + 1 > H)
			solve(x + 1, 1, select, origin);
		else
			solve(x, y + 1, select, origin);
		return;
	}
	
	able[x][y] = true;
	able[x + 1][y] = true;
	dir[x][y][x + 1] = true;
	dir[x + 1][y][x] = true;

	if (y + 1 > H)
		solve(x + 1, 1, select - 1, origin);
	else
		solve(x, y + 1, select - 1, origin);

	able[x][y] = false;
	able[x + 1][y] = false;
	dir[x][y][x + 1] = false;
	dir[x + 1][y][x] = false;

	if (y + 1 > H)
		solve(x + 1, 1, select, origin);
	else
		solve(x, y + 1, select, origin);
}

int main()
{
	cin >> N >> M >> H;

	for (int i = 0, a, b; i < M; i++)
	{
		cin >> a >> b;
		able[b][a] = true;
		able[b + 1][a] = true;
		dir[b][a][b + 1] = true;
		dir[b + 1][a][b] = true;
	}

	for (int i = 0; i <= 3; i++)
		solve(1, 1, i, i);

	cout << -1;
}