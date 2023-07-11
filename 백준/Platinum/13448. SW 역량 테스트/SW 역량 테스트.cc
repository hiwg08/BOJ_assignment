#include <bits/stdc++.h>
#define ll long long
#define m get<0>
#define t get<1>
#define p get<2>

using namespace std;

ll DP[51][100001]{ 0 };

ll N, T;

ll M[51]{ 0 }, P[51]{ 0 }, R[51]{ 0 };

vector<tuple<ll, ll, ll>> V;

ll solve(ll Idx, ll limi)
{
	if (Idx >= N)
		return 0;

	ll& ret = DP[Idx][limi];

	if (ret != 0x7f7f7f7f7f7f7f7f)
		return ret;

	ret = solve(Idx + 1, limi);

	if (limi + t(V[Idx]) <= T && (m(V[Idx]) - ((limi + t(V[Idx])) * p(V[Idx]))) > 0)
		ret = max(ret, solve(Idx + 1, limi + t(V[Idx])) + (m(V[Idx]) - ((limi + t(V[Idx])) * p(V[Idx]))));

	return ret;
}

bool cmp(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b)
{
	return t(b) * p(a) > t(a) * p(b);
}

int main()
{
	cin >> N >> T;

	for (ll i = 0; i < N; i++)
		cin >> M[i];

	for (ll i = 0; i < N; i++)
		cin >> P[i];

	for (ll i = 0; i < N; i++)
		cin >> R[i];

	for (ll i = 0; i < N; i++)
		V.push_back({ M[i], R[i], P[i] });

	sort(V.begin(), V.end(), cmp);

	memset(DP, 0x7f, sizeof(DP));

	cout << solve(0, 0);
}