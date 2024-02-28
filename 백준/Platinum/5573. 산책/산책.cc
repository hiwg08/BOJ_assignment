#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll H, W, N;

ll bor[1001][1001]{ 0 };

ll dp[1001][1001]{ 0 };

int main()
{
	cin >> H >> W >> N;

	for (ll i = 0; i < H; i++)
	{
		for (ll j = 0; j < W; j++)
			cin >> bor[i][j];
	}

	N--;

	dp[0][0] = N;

	for (ll i = 0; i < H; i++)
	{
		for (ll j = 0; j < W; j++)
		{ 
			dp[i][j + 1] += dp[i][j] >> 1;
			dp[i + 1][j] += dp[i][j] >> 1;

			if ((dp[i][j] & 1) == 1) // 상근이가 도달한 횟수가 홀수일 때
			{
				if (bor[i][j] == 0) // 아래로 움직였으면 아래 방향으로의 횟수를 1 추가
					dp[i + 1][j] += 1;
				else // 오른쪽으로 움직였으면 오른쪽 방향으로의 횟수를 1 추가
					dp[i][j + 1] += 1;
			}

			bor[i][j] = (bor[i][j] + dp[i][j]) % 2; // D(i, j) 값을 토대로 좌표 값을 바로 변경
		}
	}

	ll sx = 0, sy = 0;

	while (sx < H && sy < W)
	{
		if (bor[sx][sy] == 0)
			sx++;
		else
			sy++;
	}

	cout << sx + 1 << " " << sy + 1;
}