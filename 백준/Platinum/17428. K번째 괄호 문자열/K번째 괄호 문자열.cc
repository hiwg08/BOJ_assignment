#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, K, DP[51][51]{ 0 };

ll solve(ll L, ll R)
{
	if (L < 0)
		return 0;

	if (L + R == 0)
		return 1;

	ll& ret = DP[L][R];

	if (ret != -1)
		return ret;
	
	ret = solve(L - 1, R);

	if (L < R)
		ret += solve(L, R - 1);

	return ret;
}

int main()
{
	cin >> N >> K;

	memset(DP, -1, sizeof(DP));
	
	if (solve(N / 2, N / 2) <= K)
	{
		cout << -1 << '\n';
		exit(0);
	}

	ll L = N / 2, R = N / 2;

	while (L != 0 || R != 0)
	{
		ll upper = 0;

		if (L - 1 >= 0)
			upper = DP[L - 1][R];

		if (K < upper)
		{
			cout << "(";
			L--;
		}
		else
		{
			cout << ")";
			K -= upper;
			R--;
		}
	}

	cout << '\n';
}