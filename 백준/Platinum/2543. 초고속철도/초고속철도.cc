#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second
#define MOD (ll)(20070713)

using namespace std;

ll N;

vector<pll> V;

ll DP[100001]{ 0 };

ll solve(ll Idx)
{
	if (Idx >= N)
		return 1;

	ll& ret = DP[Idx];

	if (ret != -1)
		return ret;

	ll nxt = (ll)(lower_bound(V.begin(), V.end(), make_pair((ll)V[Idx].y + 1, (ll)-987654321)) - V.begin());

	return ret = (solve(Idx + 1) % MOD + solve(nxt) % MOD) % MOD;
}

int main()
{
	cin >> N;

	for (ll i = 0, a, b; i < N; i++)
	{
		cin >> a >> b;
		V.push_back({ a, b });
	}

	sort(V.begin(), V.end());

	memset(DP, -1, sizeof(DP));

	cout << solve(0);
}