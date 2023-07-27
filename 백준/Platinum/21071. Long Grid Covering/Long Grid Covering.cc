#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(1e9 + 7)
#define vl vector<ll>
#define vvl vector<vl>

using namespace std;

ll T, a;

ll precomp[]{ 1, 1, 3, 10, 23, 62 };

void add_m(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

void mul_m(ll& ret, ll params)
{
	ret *= params;
	ret %= MOD;
}

vvl ori{
	{1, 2, 6, 1, 0, MOD - 1},
	{1, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0},
	{0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 1, 0}
};

vvl dev_con(ll pows)
{
	if (pows == 1)
		return ori;

	vvl ret(6, vl(6, 0));

	if (pows % 2 != 0)
	{
		vvl T1 = dev_con(pows - 1);

		for (ll i = 0; i < 6; i++)
		{
			for (ll j = 0; j < 6; j++)
			{
				for (ll k = 0; k < 6; k++)
				{
					ll inn = ori[i][k];
					mul_m(inn, T1[k][j]);
					add_m(ret[i][j], inn);
				}
			}
		}

		return ret;
	}
	

	vvl T1 = dev_con(pows / 2);

	for (ll i = 0; i < 6; i++)
	{
		for (ll j = 0; j < 6; j++)
		{
			for (ll k = 0; k < 6; k++)
			{
				ll inn = T1[i][k];
				mul_m(inn, T1[k][j]);
				add_m(ret[i][j], inn);
			}
		}
	}

	return ret;
}

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> a;

		if (a <= 5)
			cout << precomp[a] << '\n';
		else
		{
			vvl ans = dev_con(a - 5);

			ll total = 0;

			for (ll i = 0; i < 6; i++)
			{
				ll inn = ans[0][i];
				mul_m(inn, precomp[5 - i]);
				add_m(total, inn);
			}

			cout << total << '\n';
		}
	}
}