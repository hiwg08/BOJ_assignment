#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(1e9 + 7)

using namespace std;

ll DP[2][501][501]{ 0 };

ll N, ans;

char board[501][501]{ 0 };

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

bool monge(ll kx, ll ky, ll jx, ll jy)
{
	if (kx > jx || ky > jy)
		return false;
	return true;
}

void solve()
{
	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j <= i; j++)
		{
			ll jx = N - 1 - j, jy = (2 * (N - 1)) - i - jx;

			for (ll k = 0; k <= i; k++) // k가 왼편, j가 오른편
			{ 
				ll  kx = k, ky = i - kx;

				if (!monge(kx, ky, jx, jy))
					continue;


				if (i == 0)
				{
					if (board[jx][jy] == board[kx][ky])
						DP[i % 2][j][k] = 1;
				}
				else
				{
					if (board[jx][jy] == board[kx][ky])
					{
						if (j - 1 >= 0 && k - 1 >= 0)
							add_mod(DP[i % 2][j][k], DP[(i - 1) % 2][j - 1][k - 1]);

						if (j - 1 >= 0)
							add_mod(DP[i % 2][j][k], DP[(i - 1) % 2][j - 1][k]);

						if (k - 1 >= 0)
							add_mod(DP[i % 2][j][k], DP[(i - 1) % 2][j][k - 1]);

						add_mod(DP[i % 2][j][k], DP[(i - 1) % 2][j][k]);
						
					}
				}

				if (i == N - 1)
					add_mod(ans, DP[i % 2][j][k]);

			}
		
		}
		if (i != 0)
			memset(DP[(i - 1) % 2], 0, sizeof(DP[(i - 1) % 2]));
	}
}

int main()
{
	cin >> N;

	for (ll i = 0; i < N; i++)
	{
		string S; cin >> S;

		for (ll j = 0; j < N; j++)
			board[i][j] = S[j];
	}

	solve();

	cout << ans;
}