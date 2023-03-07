#include <bits/stdc++.h>

using namespace std;

int N, total, ans = INT_MAX, start_y, brother;

int Arr[21][21]{ 0 };

bool DP[21][21][40001]{ 0 };

int pre_sum[21][21]{ 0 };

void solve(int x, int y, int sum)
{
	if (x == 0)
		return;

	if (DP[x][y][sum])
		return;

	for (int nxt = y; nxt >= 0; nxt--)
	{
		if (!DP[x][nxt][sum + pre_sum[x][nxt]])
		{
			DP[x][nxt][sum + pre_sum[x][nxt]] = true;
			solve(x - 1, nxt, sum + pre_sum[x][nxt]);
		}
	}
}

void Input()
{
	cin >> N;

	for (int y = N; y >= 1; y--)
	{
		for (int x = 1; x <= N; x++)
		{
			cin >> Arr[x][y];
			total += Arr[x][y];
		}
	}

	for (int x = 1; x <= N; x++)
	{
		for (int y = 1; y <= N; y++)
			pre_sum[x][y] = pre_sum[x][y - 1] + Arr[x][y];
	}
}

void reconstruct(int x, int params)
{
	if (x > N)
		return;

	for (int nxt = start_y; nxt <= N; nxt++)
	{
		if (DP[x][nxt][params])
		{
			cout << nxt << " ";
			reconstruct(x + 1, params - pre_sum[x][nxt]);
			return;
		}
	}
}

int main()
{
	Input();

	solve(N, N, 0);

	for (int i = 0; i <= N; i++)
	{
		for (int sum = 0; sum <= total; sum++)
		{
			if (DP[1][i][sum]) // 동생이 갖는 게 sum, 그렇다면 형은? total - sum!
			{
				if (ans > abs(2 * sum - total))
				{
					ans = abs(2 * sum - total);
					brother = sum;
					start_y = i;
				}
			}
		}
	}

	cout << ans << '\n';

	reconstruct(1, brother);

	cout << '\n';
}