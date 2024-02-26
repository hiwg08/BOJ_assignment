#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair<ll, ll> dp[1001][1001];

ll H, W, N;

ll bor[1001][1001]{ 0 }, ans[1001][1001]{ 0 };

int main()
{
	cin >> H >> W >> N;

	for (ll i = 0; i < H; i++)
	{
		for (ll j = 0; j < W; j++)
			cin >> bor[i][j];
	}

	N--;

	if (bor[0][0] == 0) // 0 1 0 1 0 1 0 1 0 ...
	{
		if (N % 2 == 0) // 짝수 0 1 0 1 0 1
			dp[0][0] = { N >> 1, N >> 1 };
		else // 홀수 0 1 0 1 0
			dp[0][0] = { (N >> 1) + 1, N >> 1 };
	}
	else // 1 0 1 0 1 0 1 0 1 ...
	{
		if (N % 2 == 0)  // 짝수
			dp[0][0] = { N >> 1, N >> 1 };
		else // 홀수
			dp[0][0] = { N >> 1, (N >> 1) + 1 };
	}

	for (ll i = 1; i < W; i++) // 가로 방향
	{
		// dp[0][i - 1]의 값을 이어 받아야 한다
		auto [_down, _right] = dp[0][i - 1];
		
		if (_right % 2 == 0)
		{
			if (bor[0][i] == 0) // 0 1 0 1
				dp[0][i] = { _right >> 1, _right >> 1 };
			else // 0 1 0 1
				dp[0][i] = { _right >> 1, _right >> 1 };
		}
		else
		{
			if (bor[0][i] == 0) // 1 0 1 0 1 0 1
				dp[0][i] = { (_right >> 1) + 1, _right >> 1 };
			else //  0 1 0 1 0 1 0
				dp[0][i] = { _right >> 1, (_right >> 1) + 1 };
		}
	}

	for (ll j = 1; j < H; j++) // 세로 방향
	{
		// dp[j - 1][0]의 값을 이어 받아야 한다
		auto [_down, _right] = dp[j - 1][0];

		if (_down % 2 == 0)
		{
			if (bor[j][0] == 0) // 0 1 0 1
				dp[j][0] = { _down >> 1, _down >> 1 };
			else // 1 0 1 0
				dp[j][0] = { _down >> 1, _down >> 1 };
		}
		else
		{
			if (bor[j][0] == 0) // 0 1 0 1 0 1 0
				dp[j][0] = { (_down >> 1) + 1, _down >> 1 };
			else // 1 0 1 0 1 0 1
				dp[j][0] = { _down >> 1, (_down >> 1) + 1 };
		}
	}

	for (ll i = 1; i < H; i++)
	{
		for (ll j = 1; j < W; j++)
		{
			auto [down_n, right_n] = dp[i - 1][j];
			auto [down_w, right_w] = dp[i][j - 1];
			
			if ((right_w + down_n) % 2 == 0)
			{
				if (bor[i][j] == 0) // 0 1 0 1
					dp[i][j] = { (right_w + down_n) / 2, (right_w + down_n) / 2 };
				else // 1 0 1 0
					dp[i][j] = { (right_w + down_n) / 2, (right_w + down_n) / 2 };
			}
			else
			{
				if (bor[i][j] == 0) // 0 1 0 1
					dp[i][j] = { (right_w + down_n) / 2 + 1, (right_w + down_n) / 2 };
				else // 1 0 1 0
					dp[i][j] = { (right_w + down_n) / 2, (right_w + down_n) / 2 + 1 };
			}
		}
	}

	for (ll i = 0; i < H; i++)
	{
		for (ll j = 0; j < W; j++)
		{
			auto [x, y] = dp[i][j];

			ans[i][j] = (bor[i][j] + x + y) % 2 == 0 ? 0 : 1;

		//	cout << x + y << " ";
		}
		// cout << '\n';
	}

	ll cx = 0, cy = 0;

	while (cx < H && cy < W)
	{
		if (ans[cx][cy] == 0)
			cx++;
		else
			cy++;
	}

	cout << cx + 1 << " " << cy + 1;
}