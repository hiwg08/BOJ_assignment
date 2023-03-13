#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll DP[11][222][222]{ 0 };

ll N, M, K;

ll solve(ll Idx, ll sum, ll start)
{
	if (sum < 0)
		return 0;

	if (Idx >= N)
	{
		if (sum == 0)
			return 1;
		return 0;
	}

	ll& ret = DP[Idx][sum][start];

	if (ret != -1)
		return ret;

	ret = 0;

	if (Idx == N - 1)
		return ret = solve(Idx + 1, sum - start, 1);

	for (ll i = start; i <= 220; i++)
		ret += solve(Idx + 1, sum - start, i);
	
	return ret;
}

void reconstruct(ll Idx, ll sum, ll start, ll cut)
{
	if (Idx >= N)
		return;

	ll nu = 0;

	for (ll i = start; i <= 220; i++)
	{
		nu += DP[Idx][sum][i];

		if (nu < cut)
			continue;

		cout << i << " ";
		reconstruct(Idx + 1, sum - i, i, cut - nu + DP[Idx][sum][i]);
		return;
	}
}

void Input()
{
	cin >> N >> M >> K;

	memset(DP, -1, sizeof(DP));

	for (ll i = 1; i <= 220; i++)
		solve(0, M, i);
}

int main()
{
	Input();

	reconstruct(0, M, 1, K);

	cout << '\n';
}