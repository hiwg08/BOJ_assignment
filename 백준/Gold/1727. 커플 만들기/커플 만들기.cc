#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

ll N, M, L[1001]{ 0 }, R[1001]{ 0 }, DP[1001][1001]{ 0 };

ll solve(ll man, ll woman)
{
	if (man == -1 || woman == -1)
		return 0;

	ll& ret = DP[man][woman];

	if (ret != -1)
		return ret;

	ret = INT_MAX;

	if (man == woman)
		ret = solve(man - 1, woman - 1) + abs(L[man] - R[woman]);

	else if (man > woman)
		ret = min({ ret, solve(man - 1, woman), solve(man - 1, woman - 1) + abs(L[man] - R[woman]) });

	else if (man < woman)
		ret = min({ ret, solve(man, woman - 1), solve(man - 1, woman - 1) + abs(L[man] - R[woman]) });

	return ret;
}

int main()
{
	fastio;

	cin >> N >> M;

	for (ll i = 0; i < N; i++)
		cin >> L[i];

	for (ll i = 0; i < M; i++)
		cin >> R[i];

	sort(L, L + N);  sort(R, R + M);

	memset(DP, -1, sizeof(DP));

	cout << solve(N - 1, M - 1) << '\n';
}