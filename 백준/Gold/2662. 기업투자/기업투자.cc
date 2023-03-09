#include <bits/stdc++.h>

using namespace std;

int N, M;

int cost[301]{ 0 };

int profit[21][301]{ 0 };

int DP[21][301]{ 0 };

int trace[21][301]{ 0 };

int solve(int Idx, int money) // Idx : 기업임.
{
	if (Idx >= M)
		return 0;

	int& ret = DP[Idx][money];

	if (ret != -1)
		return ret;

	ret = solve(Idx + 1, money); // 현재 기업을 선택하지 않고 넘기는 경우의 수

	for (int i = 0; i < N; i++)
	{
		if (money - cost[i] >= 0) // 이 때만 값 갱신 해야한다.
		{
			int T1 = solve(Idx + 1, money - cost[i]) + profit[Idx][i];

			if (T1 > ret) // max일 때 적용
			{
				ret = T1;
				trace[Idx][money] = cost[i];
			}
		}
	}

	return ret;
}

void reconstruct(int Idx, int params)
{
	if (Idx >= M)
		return;

	cout << trace[Idx][params] << " ";

	reconstruct(Idx + 1, params - trace[Idx][params]);
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> cost[i];

		for (int j = 0; j < M; j++)
			cin >> profit[j][i];
	}

	memset(DP, -1, sizeof(DP));

	cout << solve(0, N) << '\n';

	reconstruct(0, N);
	// 각 기업에 투자한 액수임
}