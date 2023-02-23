#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(1e9 + 7)

using namespace std;

ll N, C, cnt = 0;

ll DP[1001][10001]{ 0 };

ll S[2][10001]{ 0 };

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}
void sub_mod(ll& ret, ll params)
{
	ret = (ret - params + MOD) % MOD;
}

int main()
{
	DP[0][0] = 1;

	S[0][0] = 1;

	cin >> N >> C;

	for (ll i = 1; i <= N; i++)
	{
		ll j = 0;

		for (j = 0; j <= cnt; j++)
		{
			if (j > C)
				break;

			if (j < i)
				DP[i][j] = S[0][j];
			else
			{
				ll A = S[0][j];
				sub_mod(A, S[0][j - i]);
				DP[i][j] = A;
			}

			if (j == 0)
				S[1][j] = DP[i][j];
			else
			{
				ll A = S[1][j - 1];
				add_mod(A, DP[i][j]);
				S[1][j] = A;
			}
		}

		cnt += i;

		while (j - 1 >= 0 && j <= cnt)
		{
			if (j > C)
				break;
			S[1][j] = S[1][j - 1];
			j++;
		}

		for (j = 0; j <= cnt; j++)
		{
			if (j > C)
				break;
			S[0][j] = S[1][j];
			S[1][j] = 0;
		}
	}

	cout << DP[N][C] << '\n';
}