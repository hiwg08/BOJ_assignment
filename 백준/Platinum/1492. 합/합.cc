#include <bits/stdc++.h>
#define ll long long
#define o (ll)1
#define MOD (ll)(1e9 + 7)
#define vl vector<ll>
#define vvl vector<vl>

using namespace std;

ll N, K;

ll fac[51][51]{ 0 };

ll f(ll L, ll R)
{
	if (L == R || R == 0)
		return 1;

	ll& ret = fac[L][R];

	if (ret != -1)
		return ret;

	return ret = ((f(L - 1, R - 1) % MOD) + (f(L - 1, R) % MOD)) % MOD;
}

vvl V;

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

void precomp()
{
	memset(fac, -1, sizeof(fac));

	V[0][0] = 1, V[0][K + 1] = 1;

	for (ll i = 1; i < K + 2; i++)
	{
		for (ll j = 1; j <= i; j++)
			V[i][j] = f((i - 1), (j - 1));
	}
}

vvl solve(ll pows)
{
	vvl ret; ret.resize(K + 2, vl(K + 2, 0));

	if (pows == 0)
	{
		for (ll i = 0; i < K + 2; i++)
			ret[i][i] = 1;

		return ret;
	}

	if ((pows & 1) != 0)
	{
		vvl T1 = solve(pows - 1);

		for (ll i = 0; i < K + 2; i++)
		{
			for (ll j = 0; j < K + 2; j++)
			{
				for (ll k = 0; k < K + 2; k++)
				{
					ll Q = T1[i][k];
					mul_mod(Q, V[k][j]);
					add_mod(ret[i][j], Q);
				}
			}
		}

		return ret;
	}

	vvl T1 = solve(pows >> 1);

	for (ll i = 0; i < K + 2; i++)
	{
		for (ll j = 0; j < K + 2; j++)
		{
			for (ll k = 0; k < K + 2; k++)
			{
				ll Q = T1[i][k];
				mul_mod(Q, T1[k][j]);
				add_mod(ret[i][j], Q);
			}
		}
	}

	return ret;
}

int main()
{
	cin >> N >> K;

	V.resize(K + 2, vl(K + 2, 0));

	precomp();

	if (N == 1)
	{
		cout << 1;
		exit(0);
	}

	vl Q; Q.resize(K + 2);

	Q[0] = 1;

	for (ll i = 1; i < K + 2; i++)
		Q[i] = (o << (i - 1)) % MOD;


	vvl res = solve(N - 1); 

	ll ans = 0;

	for (ll i = 0; i < K + 2; i++)
	{
		ll tmp = res[0][i];
		mul_mod(tmp, Q[i]);
		add_mod(ans, tmp);
	}

	cout << ans;	
}