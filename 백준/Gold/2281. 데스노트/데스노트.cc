#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

ll N, M, Arr[1001]{ 0 }, DP[1001][1001]{ 0 };

ll solve(ll Idx, ll Name)
{
	if (Idx >= N || Name >= N)
		return 0;

	ll& ret = DP[Idx][Name];

	if (ret != -1)
		return ret;

	if (Name + 1 >= N) 
		ret = solve(Idx + 1, Name + 1);
	else 
		ret = solve(Idx + 1, Name + 1) + (M - Arr[Name]) * (M - Arr[Name]); // 1. 사람을 한 명 채우고 넘길 때 (일단 그 칸에는 반드시 사람 한명은 있어야 하기 때문)

	ll accum = Arr[Name] + 1, pre_n = Name + 1;

	while (true)
	{
		if (pre_n >= N)
			break;

		if (accum + Arr[pre_n] > M)
			break;

		accum += Arr[pre_n];

		if (pre_n + 1 >= N) 
			ret = min(ret, solve(Idx + 1, ++pre_n));
		else
			ret = min(ret, solve(Idx + 1, ++pre_n) + (M - accum) * (M - accum));

		accum += 1;
	}

	return ret;
}

int main()
{
	fastio;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	memset(DP, -1, sizeof(DP));

	cout << solve(0, 0) << '\n';
}