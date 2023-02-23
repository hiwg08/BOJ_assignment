#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, M, T, DP[10][1 << 10]{ 0 };

char Board[11][11]{ 0 };

bool adjecent(int Idx, int Bit, int stand_Bit)
{
	int Cnt = 0;
	
	bool flag = false;

	for (int i = 0; i < M; i++)
	{
		if (Bit & (1 << i))
		{
			if (Board[Idx][M - 1 - i] == 'x') 
				return false;

			if ((stand_Bit & (1 << (i + 1))) || (stand_Bit & (1 << (i - 1))))
				return false;

			if (!flag)
				flag = !flag;

			else
			{
				if (Cnt == 0) return false;
				Cnt = 0;
			}
		}

		else
		{
			if (flag) Cnt++;
		}
	}

	return true;
}

int solve(int Idx, int Bit)
{
	if (Idx >= N)
		return 0;
	
	int& ret = DP[Idx][Bit];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = 0; i <= (1 << M) - 1; i++)
	{
		if (!adjecent(Idx, i, Bit))
			continue;
		ret = max(ret, solve(Idx + 1, i) + (int)__builtin_popcount(i));
	}
	
	return ret;
}

int main()
{
	fastio;

	cin >> T;

	while (T--)
	{
		cin >> N >> M;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				cin >> Board[i][j];
		}

		memset(DP, -1, sizeof(DP));

		cout << solve(0, 0) << '\n';
	}
}