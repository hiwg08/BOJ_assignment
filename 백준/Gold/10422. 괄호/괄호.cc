#include <bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 5000
#define MOD 1000000007

using namespace std;

ll T, N, DP[MAX + 1]{ 0 };

ll solve(ll Idx)
{
	if (Idx == 0)
		return 1;

	ll& ret = DP[Idx];

	if (ret != -1)
		return ret;
	
	ret = 0;

	for (ll j = Idx - 2; j >= 0; j -= 2)
		ret = ((ret % MOD) + (((solve(Idx - j - 2) % MOD) * (solve(j) % MOD)) % MOD)) % MOD;

	return ret;
}

int main()
{
	fastio;
	
	cin >> T;

	memset(DP, -1, sizeof(DP));

	while (T--)
	{
		cin >> N;
		N % 2 == 0 ? cout << solve(N) << '\n' : cout << 0 << '\n';
	}
}