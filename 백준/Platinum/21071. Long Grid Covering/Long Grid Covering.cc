#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(1e9 + 7)

using namespace std;

vector<vector<ll>> basis{{ 1, 2, 1, 2, 0, 2, 0, 0, 0}, 
						 { 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 
						 { 0, 1, 0, 0, 0, 0, 0, 0, 0 },	
						 { 0, 1, 0, 1, 0, 0, 0, 0, 0 }, 
						 { 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 
						 { 0, 1, 0, 0, 0, 0, 0, 1, 0 }, 
						 { 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 
						 { 0, 0, 0, 0, 0, 0, 1, 0, 0 },
						 { 0, 0, 0, 0, 0, 0, 0, 1, 0 }};

vector<ll> rig{23, 10, 3, 5, 2, 3, 1, 1, 0};

ll T, N;

ll prec[5]{ 0, 1, 3, 10, 23 };

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

vector<vector<ll>> dev_con(ll pows)
{
	if (pows == 1)
		return basis;

	if (pows % 2 != 0)
	{
		vector<vector<ll>> ret(9, vector<ll>(9, 0));

		vector<vector<ll>> T1 = dev_con(pows - 1);

		for (ll i = 0; i < 9; i++)
		{
			for (ll j = 0; j < 9; j++)	
			{
				ll Q1 = 0;

				for (ll k = 0; k < 9; k++)
				{
					ll R = basis[i][k];
					mul_mod(R, T1[k][j]);
					add_mod(Q1, R);
				}
				ret[i][j] = Q1;
			}
		}

		return ret;
	}

	vector<vector<ll>> ret(9, vector<ll>(9, 0));

	vector<vector<ll>> T1 = dev_con(pows / 2);

	for (ll i = 0; i < 9; i++)
	{
		for (ll j = 0; j < 9; j++)
		{
			ll Q1 = 0;

			for (ll k = 0; k < 9; k++)
			{
				ll R = T1[i][k];
				mul_mod(R, T1[k][j]);
				add_mod(Q1, R);
			}
			ret[i][j] = Q1;
		}
	}

	return ret;
}

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> N;

		if (N <= 4)
		{
			cout << prec[N] << '\n';
			continue;
		}
		
		vector<vector<ll>> T1 = dev_con(N - 4);

		ll ans = 0;

		for (ll i = 0; i < 9; i++)
		{
			ll R = T1[0][i];
			mul_mod(R, rig[i]);
			add_mod(ans, R);
		}

		cout << ans << '\n';
	}
}