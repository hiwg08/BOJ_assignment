#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(1e9 + 7)

using namespace std;

ll N;

// answer = Fn * Fn+1

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
	if (pows == 0)
	{
		vector<vector<ll>> ans = { {1, 0}, {0, 1} };

		return ans;
	}
	
	if (pows % 2 != 0)
	{
		vector<vector<ll>> T1 = dev_con(pows - 1);

		vector<vector<ll>> ans = { {1, 1}, {1, 0} };

		vector<vector<ll>> ret = { {0, 0}, {0, 0} };

		for (ll i = 0; i < 2; i++)
		{
			for (ll j = 0; j < 2; j++)
			{
				for (ll k = 0; k < 2; k++)
				{
					ll T = T1[i][k];
					mul_mod(T, ans[k][j]);
					add_mod(ret[i][j], T);
				}
			}
		}

		return ret;
	}

	vector<vector<ll>> T1 = dev_con(pows / 2);

	vector<vector<ll>> ret = { {0, 0}, {0, 0} };

	for (ll i = 0; i < 2; i++)
	{
		for (ll j = 0; j < 2; j++)
		{
			for (ll k = 0; k < 2; k++)
			{
				ll T = T1[i][k];
				mul_mod(T, T1[k][j]);
				add_mod(ret[i][j], T);
			}
		}
	}

	return ret;
}

int main()
{
	cin >> N;

	vector<vector<ll>> V = dev_con(N);

	ll T = V[0][0];

	mul_mod(T, V[0][1]);

	cout << T;
}