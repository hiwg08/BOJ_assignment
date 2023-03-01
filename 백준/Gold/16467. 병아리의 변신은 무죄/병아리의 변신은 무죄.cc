#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(1e8 + 7)

using namespace std;

ll T;

ll K, N;

ll dev_con(ll pows, ll params)
{
	if (pows == 0)
		return 1;

	if (pows % 2 != 0)
		return ((params % MOD) * (dev_con(pows - 1, params) % MOD)) % MOD;

	ll T = dev_con(pows / 2, params);

	return ((T % MOD) * (T % MOD)) % MOD;
}

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

void calc_matrix(vector<vector<ll>>& ret, vector<vector<ll>> params1, vector<vector<ll>> params2)
{
	for (ll i = 0; i <= K; i++)
	{
		for (ll j = 0; j <= K; j++)
		{
			ll cnt = 0;
			for (ll q = 0; q <= K; q++)
			{
				ll A = params1[i][q];
				mul_mod(A, params2[q][j]);
				add_mod(cnt, A);
			}
			ret[i][j] = cnt;
		}
	}
}

vector<vector<ll>> dev_con_2(ll pows, vector<vector<ll>> params)
{
	vector<vector<ll>> ans = vector<vector<ll>>(K + 1, vector<ll>(K + 1, 0));
	
	if (pows == 0)
	{
		for (ll i = 0; i <= K; i++)
			ans[i][i] = 1;

		return ans;
	}

	if (pows % 2 != 0)
	{
		vector<vector<ll>> T1 = dev_con_2(pows - 1, params);
		calc_matrix(ans, T1, params);
		return ans;
	}

	vector<vector<ll>> T1 = dev_con_2(pows / 2, params);

	calc_matrix(ans, T1, T1);

	return ans;
}

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> K >> N;

		vector<vector<ll>> matrix = vector<vector<ll>>(K + 1, vector<ll>(K + 1, 0));

		for (ll i = 0; i <= K; i++)
		{
			for (ll j = 0; j <= K; j++)
			{
				if (i == 0)
				{
					if (j == 0 || j == K)
						matrix[i][j] = 1;
				}
				else
				{
					if (j == i - 1)
						matrix[i][j] = 1;
				}
			}
		}

		if (K == 0)
			cout << dev_con(N, 2) << '\n';
		else
		{
			vector<vector<ll>> V = dev_con_2(N, matrix);

			cout << V[0][0] << '\n';
		}
	}
}