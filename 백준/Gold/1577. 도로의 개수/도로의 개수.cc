#include <bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

ll N, M, K, DP[101][101]{ 0 };

map<pair<ll, ll>, vector<pair<ll, ll>>> Construction;

bool CHK(int L, int R, int N_L, int N_R)
{
	if (N_L > N || N_R > M)
		return false;

	for (auto e : Construction[{L, R}])
	{
		if (e.first == N_L && e.second == N_R)
			return false;
	}

	return true;
}

ll Solve(int L, int R)
{
	if (L == N && R == M)
		return 1;

	ll& ret = DP[L][R];

	if (ret != -1)
		return ret;

	ret = 0;

	if (CHK(L, R, L, R + 1))
		ret += Solve(L, R + 1);

	if (CHK(L, R, L + 1, R))
		ret += Solve(L + 1, R);

	return ret;
}

int main()
{
	fastio;

	cin >> N >> M >> K;

	for (int i = 0; i < K; i++)
	{
		ll a, b, c, d; cin >> a >> b >> c >> d;
		Construction[{a, b}].push_back({c, d});
		Construction[{c, d}].push_back({a, b});
	}

	memset(DP, -1, sizeof(DP));

	cout << Solve(0, 0) << '\n';
}