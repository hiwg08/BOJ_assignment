#include <bits/stdc++.h>

using namespace std;

long long N, M, Arr[101]{ 0 }, DP[101][101]{ 0 };

long long Solve(long long Idx, long long Interval)
{
	if (Idx >= N)
	{
		if (Interval != 0)
			return INT_MIN;
		return 0;
	}

	long long& ret = DP[Idx][Interval];

	if (ret != 0x7f7f7f7f7f7f7f7f)
		return ret;

	ret = Solve(Idx + 1, Interval);

	long long temp = 0;

	for (long long i = Idx; i < N; i++)
	{
		temp += Arr[i];
		ret = max(ret, Solve(i + 2, Interval - 1) + temp);
	}

	return ret;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	memset(DP, 0x7f, sizeof(DP));

	cout << Solve(0, M) << '\n';
}