#include <bits/stdc++.h>

using namespace std;

int N;

int precomp[256][256]{ 0 };

int DP[256][256]{ 0 };

int arr[256]{ 0 };

int solve(int L, int R)
{
	if (L == R)
		return 0;

	int& ret = DP[L][R];

	if (ret != -1)
		return ret;

	ret = INT_MAX;

	for (int i = L; i < R; i++)
		ret = min(ret, solve(L, i) + solve(i + 1, R) + abs(precomp[L][i] - precomp[i + 1][R]));

	return ret;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
	{
		precomp[i][i] = arr[i];

		for (int j = i + 1; j < N; j++)
			precomp[i][j] = min(precomp[i][j - 1], arr[j]);
	}

	memset(DP, -1, sizeof(DP));

	cout << solve(0, N - 1);
}