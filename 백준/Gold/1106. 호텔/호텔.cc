#include <bits/stdc++.h>
#define MAX 2000

using namespace std;

int C, N, ans = INT_MAX;

int cost[21]{ 0 }, client[21]{ 0 };

int DP[MAX + 1]{ 0 }; // 그냥 넉넉하게 잡아버리는 게 마음 편함

int main()
{
	cin >> C >> N;

	for (int i = 0; i < N; i++)
		cin >> cost[i] >> client[i];

	memset(DP, 0x7f, sizeof(DP));

	DP[0] = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = client[i]; j <= MAX; j++)
			DP[j] = min(DP[j], DP[j - client[i]] + cost[i]);
	}

	for (int i = C; i <= MAX; i++)
	{
		if (DP[i] != 0x7f7f7f7f)
			ans = min(ans, DP[i]);
	}

	cout << ans;
}

// DP[C] : c명을 늘리기 위해 써야하는 돈의 최솟값