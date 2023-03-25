#include <bits/stdc++.h>

using namespace std;

int N, M, ans = INT_MAX;

int memo[101]{ 0 }, cost[101]{ 0 };

int DP[10001]{ 0 };

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> memo[i];

	for (int i = 0; i < N; i++)
		cin >> cost[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = 10000; j >= cost[i]; j--)
			DP[j] = max(DP[j], DP[j - cost[i]] + memo[i]);
	}

	for (int i = 0; i <= 10000; i++)
	{
		if (DP[i] >= M)
			ans = min(ans, i);
	}

	cout << ans;
}

// DP[C] : C라는 비용을 갖고 소거할 수 있는 메모리의 최댓값

// time complexity : order(10000 * 100) = order(10000000)