#include <bits/stdc++.h>

using namespace std;

int N, K;

int DP[41]{ 0 }, Sum_DP[41]{ 0 }, Ans;

int displace_solve(int Idx)
{
	if (Idx == 0 || Idx == 1)
		return DP[Idx] = 1;

	int& ret = DP[Idx];

	if (ret != -1)
		return ret;

	return ret = displace_solve(Idx - 1) + displace_solve(Idx - 2);
}

int Get_Split(int x, int y)
{
	return DP[x] * Sum_DP[y] + DP[y] * Sum_DP[x] - (DP[x] * DP[y]);
}

int main()
{
	cin >> N >> K;

	memset(DP, -1, sizeof(DP));

	displace_solve(40);

	for (int i = 0; i <= 40; i++)
		i == 0 ? Sum_DP[i] = DP[i] : Sum_DP[i] = DP[i] + Sum_DP[i - 1];

	int lo = K - 1, hi = N - 1 - lo;

	Ans = DP[lo] * DP[hi];

	for (int i = 0; i < lo; i++)
		Ans += DP[hi] * Get_Split(i, lo - 1 - i);

	for (int i = 0; i < hi; i++)
		Ans += DP[lo] * Get_Split(i, hi - 1 - i);

	cout << Ans << '\n';
}