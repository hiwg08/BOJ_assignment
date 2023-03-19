#include <bits/stdc++.h>

using namespace std;

int N;

int DP[60][60]{ 0 };

vector<int> A, B;

int solve(int a, int b)
{
	if (a >= (int)A.size())
		return 0;

	int& ret = DP[a][b];

	if (ret != -1)
		return ret;

	ret = 0;

	if (A[a] > B[b])
		ret += solve(a + 1, b + 1) + 2;

	else if (A[a] == B[b])
	{
		int L = solve(a + 1, b);
		int R = solve(a + 1, b + 1) + 1;

		ret += max(L, R);
	}
	else
		ret += solve(a + 1, b);

	return ret;
}

int main()
{
	cin >> N; A.resize(N); B.resize(N);

	for (auto& iv : A)
		cin >> iv;

	for (auto& iv : B)
		cin >> iv;

	sort(A.begin(), A.end());

	sort(B.begin(), B.end());

	memset(DP, -1, sizeof(DP));

	cout << solve(0, 0) << '\n';
}