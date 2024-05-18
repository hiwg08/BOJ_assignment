#include <bits/stdc++.h>

using namespace std;

int N, M, ans = INT_MAX;

char board[51][51]{ 0 };

void input()
{
	cin >> N >> M;

	for (int x = 0; x < N; x++)
	{
		string S; cin >> S;

		for (int y = 0; y < M; y++)
			board[x][y] = S[y];

	}
}

void check(int px, int py)
{
	int ver1 = 0, ver2 = 0;

	for (int x = px; x < px + 8; x++)
	{
		for (int y = py; y < py + 8; y++)
		{
			if ((x + y) % 2 == 0)
			{
				if (board[x][y] != 'B')
					ver1++;
				if (board[x][y] != 'W')
					ver2++;
			}
			else
			{
				if (board[x][y] != 'W')
					ver1++;
				if (board[x][y] != 'B')
					ver2++;
			}
		}
	}

	ans = min(ans, min(ver1, ver2));
}

int main()
{
	input();

	for (int x = 0; x <= N - 8; x++)
	{
		for (int y = 0; y <= M - 8; y++)
			check(x, y);
	}

	cout << ans;
}