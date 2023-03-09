#include <bits/stdc++.h>

using namespace std;

int N;

int Arr[1001]{ 0 };

int DP[1001][1001]{ 0 };

int solve(int L, int R)
{
	if (L > R)
		return 0;

	int& ret = DP[L][R];

	if (ret != -1)
		return ret;

	ret = solve(L + 1, R);

	for (int i = R; i > L; i--)
	{
		if (i == R)
			ret = max(ret, solve(L + 1, i - 1) + (Arr[L] == Arr[i]));
	
		else if (i == L + 1)
			ret = max(ret, solve(i + 1, R) + (Arr[L] == Arr[i]));
	
		else
		{
			int LN = solve(L + 1, i - 1), RN = solve(i + 1, R);
			ret = max(ret, LN + RN + (Arr[L] == Arr[i]));
		}
	}

	return ret;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	memset(DP, -1, sizeof(DP));

	cout << solve(0, N - 1) << '\n';
}