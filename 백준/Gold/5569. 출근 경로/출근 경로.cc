#include <bits/stdc++.h>
#define MOD 100000

using namespace std;

int W, H, DP[101][101][2][2]{ 0 };

int dx[]{ 1, 0 };
int dy[]{ 0, 1 };

int solve(int x, int y, bool dir, int move)
{
	if (x >= W || y >= H)
		return 0;

	if (x == W - 1 && y == H - 1)
		return 1;

	int& ret = DP[x][y][dir][move];

	if (ret != -1)
		return ret;

	ret = 0;

	if (x == 0 && y == 0)
	{
		ret += (solve(x + dx[0], y + dy[0], 0, 0) % MOD);
		ret += (solve(x + dx[1], y + dy[1], 1, 0) % MOD);
	}
	else
	{
		if (move == 0)
		{
			ret += (solve(x + dx[dir], y + dy[dir], dir, 0) % MOD);
			ret += (solve(x + dx[!dir], y + dy[!dir], !dir, 1) % MOD);
		}
		else
			ret += (solve(x + dx[dir], y + dy[dir], dir, 0) % MOD);
	}

	return ret % MOD;
}

int main()
{
	cin >> W >> H;

	memset(DP, -1, sizeof(DP));

	cout << solve(0, 0, 0, 0)<< '\n';
}