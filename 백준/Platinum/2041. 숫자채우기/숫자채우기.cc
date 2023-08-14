#include <bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

ll N, M, Idx = 0, start = (ll)1e7;

ll board[1001][1001][2]{ 0 }, ans[1001][1001]{ 0 };

bool overthere(ll nx, ll ny)
{
	return (nx < 0 || ny < 0 || nx >= N || ny >= M);
}

void precomp()
{
	for (ll i = 0; i < N; i++) // 여기서부터는 (0, 0) ~ (2, 0) 까지
	{
		ll nx = i, ny = 0;

		while (true)
		{
			if (!overthere(nx + 1, ny))
				board[nx][ny][0] = ++Idx;
			if (!overthere(nx, ny + 1))
				board[nx][ny][1] = ++Idx;

			nx--, ny++;

			if (overthere(nx, ny))
				break;
		}
	}

	for (ll j = 1; j < M; j++) // 여기서부터는 (2, 1) ~ (2, 7) 까지
	{
		ll nx = N - 1, ny = j;

		while (true)
		{
			if (!overthere(nx + 1, ny))
				board[nx][ny][0] = ++Idx;
			if (!overthere(nx, ny + 1))
				board[nx][ny][1] = ++Idx;

			nx--, ny++;

			if (overthere(nx, ny))
				break;
		}
	}
}

void solve()
{
	bool flag = true;

	for (ll j = 0; j < M; j++)
	{
		if (j != 0)
		{
			if (j % 2 != 0)
				start += board[0][j - 1][1];
			else
				start -= board[0][j - 1][1];
		}

		for (ll i = 0; i < N; i++)
		{
			if (i == 0)
				ans[i][j] = start;
			else
			{
				if (flag)
				{
					if (i % 2 != 0)
						ans[i][j] = ans[i - 1][j] + board[i - 1][j][0];
					else
						ans[i][j] = ans[i - 1][j] - board[i - 1][j][0];
				}
				else
				{
					if (i % 2 != 0)
						ans[i][j] = ans[i - 1][j] - board[i - 1][j][0];
					else
						ans[i][j] = ans[i - 1][j] + board[i - 1][j][0];
				}
			}
		}

		flag = !flag;
	}
}

int main()
{
	fastio;

	cin >> N >> M; // 일단 3 * 8 격자를 기준으로.

	precomp();

	solve();

	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < M; j++)
			cout << ans[i][j] << " ";
		cout << '\n';
	}
}