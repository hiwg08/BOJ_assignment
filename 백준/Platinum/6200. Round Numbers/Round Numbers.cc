#include <iostream>
#define ll long long
#define o (ll)1

using namespace std;

ll dp[36][36]{ 0 }, fina;

ll A, B;

ll precomp()
{
	for (ll i = 0; i <= 35; i++)
		dp[1][i] = 1;

	for (ll i = 0; i <= 35; i++)
		dp[i][0] = 1;

	for (ll i = 1; i <= 35; i++)
	{
		for (ll j = 1; j <= 35; j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
	}

	ll z1 = 0, c1 = 0;

	ll j = 35;

	for (j = 35; j >= 0; j--)
	{
		if (A & (o << j))
			break;
	}

	while (j >= 0)
	{
		if (A & (o << j))
			c1++;
		else
			z1++;
		j--;
	}

	return (z1 >= c1);
}

ll solve(ll params)
{
	ll ret = 0, i = 35;

	for (i = 35; i >= 0; i--)
	{
		if (params & (o << i))
			break;
	}

	ll ori = i, z1 = 0, c1 = 0;

	while (i >= 0)
	{
		if (params & (o << i))
		{
			if (ori != i)
			{
				z1++;

				for (ll k = 0; k <= i; k++)
				{
					if (c1 + k <= z1 + (i - k))
						ret += dp[i][k];
				}

				z1--, c1++;
			}
		
			else
			{
				c1++;

				for (ll q = i - 1; q >= 1; q--)
				{
					for (ll k = 0; k <= q; k++)
					{
						if (c1 + k <= z1 + (q - k))
							ret += dp[q][k];
					}
				}
			}
		}
		else
			z1++;

		i--;
	}

	if (z1 >= c1)
		ret++;
	
	return ret;
}

int main(void)
{
	cin >> A >> B;

	fina = precomp();

	cout << solve(B) - solve(A) + fina;
}