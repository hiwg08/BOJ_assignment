#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end();
#define MOD (ll)(1e9 + 7)

using namespace std;

ll T, N;

ll DP[301][251]{ 0 };

ll pre_sum[301][251]{ 0 };

void add_mod(ll& ret, ll a, ll b)
{
	ret += a;
	ret %= MOD;

	ret += b;
	ret %= MOD;
}

int main()
{
	cin >> T;

	while (T--)
	{
		memset(DP, 0, sizeof(DP));

		memset(pre_sum, 0, sizeof(pre_sum));

		cin >> N;

		vector<ll> V; V.resize(N);

		vector<vector<ll>> Y;

		for (auto& iv : V)
			cin >> iv;

		for (auto e : V)
		{
			vector<ll> P;

			for (ll i = 1; i <= (ll)sqrt(e); i++)
			{
				if (e % i == 0)
					P.pb(i), P.pb(e / i);
			}

			sort(P.begin(), P.end());

			P.erase(unique(P.begin(), P.end()), P.end());

			Y.pb(P);
		}

		for (ll i = 0; i < N; i++)
		{
			for (ll j = 0; j < (ll)Y[i].size(); j++)
			{
				if (i == 0)
					DP[i][j] = 1;
				else
				{
					ll pre = (ll)(lower_bound(Y[i - 1].begin(), Y[i - 1].end(), Y[i][j]) - Y[i - 1].begin()), nxt = pre - 1;

					if (pre < (ll)Y[i - 1].size() && Y[i - 1][pre] == Y[i][j])
						DP[i][j] = pre_sum[i - 1][pre + 1];
					else
						DP[i][j] = pre_sum[i - 1][nxt + 1];
				}
				add_mod(pre_sum[i][j + 1], pre_sum[i][j], DP[i][j]);
			}
		}

		cout << pre_sum[N - 1][(ll)Y[N - 1].size()] << '\n';
	}
}