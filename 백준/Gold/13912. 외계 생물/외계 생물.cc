#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(1e9 + 7)

using namespace std;

ll H;

ll DP1[2047][2047]{ 0 };

ll DP2[11]{ 0 };

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

void mul_mod(ll& ret, ll params)
{
	ret *= params;
	ret %= MOD;
}

ll solve(ll n, ll r)
{
	if (n == r || r == 0)
		return 1;

	ll& ret = DP1[n][r];

	if (ret != -1)
		return ret;

	ll A = solve(n - 1, r);
	add_mod(A, solve(n - 1, r - 1));

	return ret = A;
}

int main()
{
	cin >> H;

	memset(DP1, -1, sizeof(DP1));

	DP2[0] = 1;

	DP2[1] = 2;

	for (ll i = 2; i <= H; i++)
	{
		ll pows = (ll)pow(2, i + 1) - 2;

		ll A = DP2[i - 1];
		mul_mod(A, DP2[i - 1]);
		mul_mod(A, solve(pows, pows / 2));
		DP2[i] = A;
	}

	cout << DP2[H] << '\n';
}