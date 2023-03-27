#include <bits/stdc++.h>

using namespace std;

int N, S;

int DP[51][51][1300]{ 0 };

int solve(int pre, int parent, int route)
{
	if (pre == N)
	{
		if (route == S)
			return 1;
		return 0;
	}

	int& ret = DP[pre][parent][route];

	if (ret != -1)
		return ret;

	if (solve(pre + 1, parent, route + pre - parent + min(1, parent - 1)))
		return ret = 1;

	if (solve(pre + 1, pre, route + 1))
		return ret = 1;

	return ret = 0;
}

int main()
{
	cin >> N >> S;

	memset(DP, -1, sizeof(DP));

	cout << solve(2, 1, 0);
}