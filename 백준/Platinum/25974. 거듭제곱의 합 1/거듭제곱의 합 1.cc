#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(1e9 + 7)

using namespace std;

ll N, P, tot;

ll stan;

ll DB[1001]{ 0 };

ll combi[1001]{ 0 };

ll fac[1001][1001]{ 0 };

ll imp[50000]{ 0 };

void mul_mod(ll& ret, ll params)
{
	ret *= params;
	ret %= MOD;
}
void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

ll f(ll L, ll R)
{
	if (L == R || R == 0)
		return 1;

	ll& ret = fac[L][R];

	if (ret != -1)
		return ret;

	return ret = ((f(L - 1, R - 1) % MOD) + (f(L - 1, R) % MOD)) % MOD;
}

ll dev_con(ll params, ll pows)
{
	if (pows == 0)
		return 1;

	if ((pows & 1) == 1)
	{
		ll T1 = dev_con(params, pows - 1);

		mul_mod(T1, params);

		return T1;
	}

	ll T1 = dev_con(params, pows >> 1);

	mul_mod(T1, T1);

	return T1;
}

void precomp()
{
	for (ll i = 1; i <= stan; i++)
		imp[i] = 1;

	for (ll outr = 0; outr <= P; outr++)
	{
		for (ll i = 1; i <= stan; i++)
		{
			add_mod(DB[outr], imp[i]);
			mul_mod(imp[i], i);
		}
	}

	memset(fac, -1, sizeof(fac));

	for (ll i = 0; i <= P; i++)
		combi[i] = f(P, i);
}

void solve()
{
	for (ll i = 1; i <= stan; i++)
		add_mod(tot, dev_con(i, P));

	ll start = stan + 1;

	while (true)
	{
		if (start <= N && N <= start + stan)
			break;

		ll remov = start - 1;

		ll tmp = 1;

		for (ll i = P; i >= 0; i--)
		{
			ll Q = combi[i];
			mul_mod(Q, tmp);
			mul_mod(tmp, remov);
			mul_mod(Q, DB[i]);
			add_mod(tot, Q);
		}

		start += stan;
	}

	for (ll i = start; i <= N; i++)
		add_mod(tot, dev_con(i, P));
}

int main()
{
	cin >> N >> P;

	if (N == 1)
	{
		cout << 1;
		exit(0);
	}

	stan = (ll)(sqrt(N));

	precomp();

	solve();

	cout << tot;
}