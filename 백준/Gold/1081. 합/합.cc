#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll L, R;

ll DP[12][10]{ 0 };

ll precomp[12]{ 0 };

void init()
{
	precomp[0] = 1;

	for (ll i = 1; i <= 11; i++)
		precomp[i] = precomp[i - 1] * 10;

	for (ll i = 1; i <= 9; i++)
		DP[1][i] += DP[1][i - 1] + i;

	for (ll i = 2; i <= 11; i++)
	{
		DP[i][0] = DP[i - 1][9];

		for (ll j = 1; j <= 9; j++)
		{
			DP[i][j] = j * precomp[i - 1] + DP[i - 1][9];
			DP[i][j] += DP[i][j - 1];
		}
	}
}

ll solve(ll params)
{
	ll total = 0, nu = 0;

	string S = to_string(params);

	for (ll i = 0; i < (ll)S.size(); i++)
	{	
		ll zari = (ll)S.length() - i;

		ll conv_l = (ll)(S[i] - '0');

		if (i == (ll)S.size() - 1)
		{
			for (ll j = 0; j <= conv_l; j++)
			{
				total += nu;
				total += j;
			}
			break;
		}

		if (S[i] == '0')
			continue;
		else if (S[i] == '1')
		{
			total += DP[zari - 1][9];
			total += nu * precomp[zari - 1];
		}
		else
		{
			total += DP[zari][conv_l - 1];
			total += nu * precomp[zari - 1] * conv_l;
		}
		nu += conv_l;

	}

	return total;
}

int main()
{
	cin >> L >> R;

	init();

	ll ans_1 = solve(L);

	ll ans_2 = solve(R);

	ll remain = 0;

	string S = to_string(L);

	for (auto e : S)
		remain += (ll)(e - '0');

	cout << ans_2 - ans_1 + remain;
}