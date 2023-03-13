#include <bits/stdc++.h>

using namespace std;

int T;

string A, B, C;

int DP[201][201]{ 0 };

int solve(int a, int b)
{
	if (a + b == (int)C.size())
		return 1;

	int& ret = DP[a][b];

	if (ret != -1)
		return ret;

	ret = 0;

	if (a < (int)A.size() && A[a] == C[a + b])
	{
		int T1 = solve(a + 1, b);

		if (T1 == 1)
			return ret = T1;
	}

	if (b < (int)B.size() && B[b] == C[a + b])
	{
		int T1 = solve(a, b + 1);

		if (T1 == 1)
			return ret = T1;
	}

	return ret;
}

int main()
{
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		cin >> A >> B >> C;

		memset(DP, -1, sizeof(DP));

		cout << "Data set " << i << ": ";

		solve(0, 0) ? cout << "yes" << '\n' : cout << "no" << '\n';
	}
}