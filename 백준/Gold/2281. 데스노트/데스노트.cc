#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, M;

ll DP[1001][1001]{ 0 };

ll Arr[1001]{ 0 };

ll solve(ll Idx, ll remain)
{
	if (Idx >= N)
		return 0;

	ll& ret = DP[Idx][remain];

	if (ret != -1)
		return ret;

	ret = 0;

	ll diff = remain - Arr[Idx]; // 남는 공간을 의미한다.

	ll mul = diff * diff;

	if (Idx + 1 < N)
	{
		ret = solve(Idx + 1, M) + mul;
		if (diff - 1 - Arr[Idx + 1] >= 0)
			ret = min(ret, solve(Idx + 1, diff - 1));
	}

	else
		ret = solve(Idx + 1, 1);

	return ret;
}

int main()
{
	cin >> N >> M;

	for (ll i = 0; i < N; i++)
		cin >> Arr[i];

	memset(DP, -1, sizeof(DP));

	cout << solve(0, M);
}