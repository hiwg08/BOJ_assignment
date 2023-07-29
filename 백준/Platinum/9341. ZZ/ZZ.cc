#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MOD (ll)(1e9 + 9)
#define vl vector<ll>
#define vvl vector<vl>

using namespace std;

ll T;

ll a, b, c, d;

ll precomp[102]{ 0 };

vvl ori;

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

vvl dev_con(ll pows)
{
	if (pows == 1)
		return ori;

	vvl ret(c + 2, vl(c + 2, 0));

	if (pows % 2 != 0)
	{
		vvl T1 = dev_con(pows - 1);

		for (ll i = 0; i <= c + 1; i++)
		{
			for (ll j = 0; j <= c + 1; j++)
			{
				for (ll k = 0; k <= c + 1; k++)
				{
					ll Q1 = ori[i][k];
					mul_mod(Q1, T1[k][j]);
					add_mod(ret[i][j], Q1);
				}
			}
		}

		return ret;
	}

	vvl T1 = dev_con(pows / 2);

	for (ll i = 0; i <= c + 1; i++)
	{
		for (ll j = 0; j <= c + 1; j++)
		{
			for (ll k = 0; k <= c + 1; k++)
			{
				ll Q1 = T1[i][k];
				mul_mod(Q1, T1[k][j]);
				add_mod(ret[i][j], Q1);
			}
		}
	}

	return ret;
}

int main()
{
	fastio;

	cin >> T;

	ori.resize(102, vl(102, 0));

	ori[0][1] = ori[1][0] = ori[1][1] = 1;

	for (ll i = 2; i <= 101; i++)
	{
		for (ll j = 0; j <= i; j++)
			ori[i][j] = 1;
	}

	while (T--)
	{
		cin >> a >> b >> c >> d;
	
		precomp[0] = a, precomp[1] = b, precomp[2] = a + b;

		for (ll i = 3; i < c + 2; i++)
			precomp[i] = (precomp[i - 1] + a) % MOD;

		if (d == 1)
		{
			cout << a << '\n';
			continue;
		}

		else if (d == 2)
		{
			cout << precomp[c + 1] << '\n';
			continue;
		}
		
		vvl res = dev_con(d - 2);
	
		ll ans[102]{ 0 };

		for (ll j = 0; j <= c + 1; j++)
		{
			ll Q1 = res[c + 1][j];
			mul_mod(Q1, precomp[j]);
			add_mod(ans[c + 1], Q1);
		}

		cout << ans[c + 1] << '\n';
	}
}