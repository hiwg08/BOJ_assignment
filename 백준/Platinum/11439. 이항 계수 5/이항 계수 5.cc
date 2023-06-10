#include <bits/stdc++.h>
#define ll long long
#define MAX (ll)(4000000)

using namespace std;

ll N, K, M, ans = 1;

ll vis[MAX + 1]{ 0 };

ll fir[MAX + 1]{ 0 };

ll sec[MAX + 1]{ 0 };

ll dev_con(ll params, ll pows)
{
	if (pows == 0)
		return 1;

	if (pows % 2 != 0)
		return ((params % M) * (dev_con(params, pows - 1) % M)) % M;

	ll T = dev_con(params, pows / 2);

	return ((T % M) * (T % M)) % M;
}

void eratos()
{
	for (ll i = 2; i <= MAX; i++)
		vis[i] = i;

	for (ll i = 2; i <= (ll)(sqrt(MAX)); i++)
	{
		if (vis[i] != i)
			continue;

		for (ll j = i * i; j <= MAX; j += i)
		{
			if (vis[j] == j)
				vis[j] = i;
		}
	}
}

void factor(ll n, bool flag)
{
	while (n > 1)
	{
		if (flag)
			fir[vis[n]]++;
		else
			sec[vis[n]]++;

		n /= vis[n];
	}
}

void solve_1(ll standard, ll limi)
{
	for (ll Idx = 0, i = standard; Idx < limi; Idx++, i--)
		factor(i, true);
}

void solve_2(ll standard)
{
	for (ll i = standard; i >= 2; i--)
		factor(i, false);
}

int main()
{
	cin >> N >> K >> M;

	if ((N / 2) < K)
		K = N - K;

	eratos();

	solve_1(N, K);

	solve_2(K);

	for (ll i = 2; i <= MAX; i++)
	{
		if (fir[i] != 0 && fir[i] > sec[i])
		{
			ll T = dev_con(i, fir[i] - sec[i]);
			ans = ((ans % M) * (T % M)) % M;
		}
	}

	cout << ans;
}