#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(1e9 + 7)

using namespace std;

ll H, W;

ll DP1[201][201]{ 0 }, DP2[6][201]{ 0 };

ll solve(ll num, ll Idx)
{
	if (Idx == 0)
	{
		if (num != 0)
			return 0;
		return 1;
	}

	ll& ret = DP1[num][Idx];

	if (ret != -1)
		return ret;

	ret = 0;

	for (ll i = 0; i <= num; i++)
	{
		if (num - i >= 0)
		{
			ret += solve(num - i, Idx - 1);
			ret %= MOD;
		}
	}

	return ret;
}

void mul_mod(ll& ret, ll par)
{
	ret *= par, ret %= MOD;
}
void add_mod(ll& ret, ll par)
{
	ret += par, ret %= MOD;
}

int main()
{
	cin >> H >> W;

	DP2[0][1] = 1;
	
	memset(DP1, -1, sizeof(DP1));

	for (ll i = 1; i <= H; i++)
	{
		for (ll j = 1; j <= W; j++)
		{
			if (DP2[i - 1][j] != 0)
			{
				for (ll k = 1; k <= W; k++)
				{
					ll T1 = 1;
					mul_mod(T1, DP2[i - 1][j]), mul_mod(T1, solve(k, j));
					add_mod(DP2[i][k], T1);
				}
			}
		}
	}

	ll Ans = 0;

	for (ll i = 1; i <= W; i++)
		add_mod(Ans, DP2[H][i]);

	cout << Ans << '\n';
}