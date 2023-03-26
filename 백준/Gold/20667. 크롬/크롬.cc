#include <bits/stdc++.h>

using namespace std;

int N, M, K, total = INT_MAX;

int cpu[101]{ 0 }, memory[101]{ 0 }, prior[101]{ 0 };

int DP[1010][600]{ 0 };

int main()
{
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		cin >> cpu[i] >> memory[i] >> prior[i];

	memset(DP, -1, sizeof(DP));

	DP[0][0] = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 1000; j >= 0; j--)
		{
			for (int k = 500; k >= prior[i]; k--)
			{
				if (DP[j][k - prior[i]] != -1)
				{
					if (j + cpu[i] > 1000)
						DP[1000][k] = max(DP[1000][k], DP[j][k - prior[i]] + memory[i]);
					else
						DP[j + cpu[i]][k] = max(DP[j + cpu[i]][k], DP[j][k - prior[i]] + memory[i]);
				}
			}
		}
	}

	for (int j = 1000; j >= 0; j--)
	{
		for (int k = 500; k >= 1; k--)
		{
			if (DP[j][k] != -1 && j >= M && DP[j][k] >= K)
				total = min(total, k);
		}
	}

	total == INT_MAX ? cout << -1 : cout << total;
}

// DP[cpu][prior] : 현재 cpu만큼 봤고, prior만큼의 합이 있을 때, 얻을 수 있는 메모리의 최댓값