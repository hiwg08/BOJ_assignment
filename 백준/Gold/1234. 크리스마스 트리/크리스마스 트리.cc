#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, R, G, B, DP[11][101][101][101]{ 0 }, F_DP[11]{ 0 };

void Init()
{
	F_DP[0] = 1;
	for (ll i = 1; i <= 10; i++)
		F_DP[i] = i * F_DP[i - 1];
}

ll solve(ll Idx, ll R, ll G, ll B)
{
	if (Idx >= N + 1)
		return 1;

	ll& ret = DP[Idx][R][G][B];

	if (ret != -1)
		return ret;
	
	ret = 0;

	if (R - Idx >= 0) ret += solve(Idx + 1, R - Idx, G, B);

	if (G - Idx >= 0) ret += solve(Idx + 1, R, G - Idx, B);

	if (B - Idx >= 0) ret += solve(Idx + 1, R, G, B - Idx);

	if (Idx % 2 == 0)
	{
		if (R - (Idx / 2) >= 0 && G - (Idx / 2) >= 0)
			ret += solve(Idx + 1, R - (Idx / 2), G - (Idx / 2), B) * (F_DP[Idx] / (F_DP[Idx / 2] * F_DP[Idx / 2]));
		if (G - (Idx / 2) >= 0 && B - (Idx / 2) >= 0)
			ret += solve(Idx + 1, R, G - (Idx / 2), B - (Idx / 2)) * (F_DP[Idx] / (F_DP[Idx / 2] * F_DP[Idx / 2]));
		if (R - (Idx / 2) >= 0 && B - (Idx / 2) >= 0)
			ret += solve(Idx + 1, R - (Idx / 2), G, B - (Idx / 2)) * (F_DP[Idx] / (F_DP[Idx / 2] * F_DP[Idx / 2]));
	}

	if (Idx % 3 == 0 && (R - (Idx / 3) >= 0 && G - (Idx / 3) >= 0 && B - (Idx / 3) >= 0))
		ret += solve(Idx + 1, R - (Idx / 3), G - (Idx / 3), B - (Idx / 3)) * (F_DP[Idx] / (F_DP[Idx / 3] * F_DP[Idx / 3] * F_DP[Idx / 3]));

	return ret;
}

int main()
{
	cin >> N >> R >> G >> B;
	
	Init();

	memset(DP, -1, sizeof(DP));

	cout << solve(1, R, G, B) << '\n';
}