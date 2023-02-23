#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, M;

ll Map[4][4]{ 0 };

ll DP[1 << 16]{ 0 };

ll solve(ll Bits)
{
	if (Bits == ((ll)1 << (N * M)) - 1)
		return 0;

	ll& ret = DP[Bits];

	if (ret != -1)
		return ret;

	ret = 0;

	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < M; j++)
		{
			ll hash = M * i + j;

			if (!(Bits & ((ll)1 << hash)))
			{
				ll nx = i, ny = j;

				ll num = Map[i][j], t_b = Bits |= (ll)1 << hash;

				ret = solve(t_b) + num;

				while (true)
				{
					if (++nx >= N)
						break;

					ll a_hash = M * nx + j;
					if ((t_b & (ll)1 << a_hash))
						break;

					t_b |= (ll)1 << a_hash;

					num *= 10, num += Map[nx][j];
					ret = max(ret, solve(t_b) + num);
				}

				num = Map[i][j], t_b = Bits | ((ll)1 << hash);

				while (true)
				{
					if (++ny >= M)
						break;

					ll a_hash = M * i + ny;
					if ((t_b & (ll)1 << a_hash))
						break;

					t_b |= (ll)1 << a_hash;

					num *= 10, num += Map[i][ny];
					ret = max(ret, solve(t_b | (ll)1 << a_hash) + num);
				}
				
				return ret;
			}
		}
	}

	return ret;
}

void Input()
{
	cin >> N >> M;

	memset(DP, -1, sizeof(DP));

	for (ll i = 0; i < N; i++)
	{
		string S; cin >> S;

		for (ll j = 0; j < M; j++)
			Map[i][j] = (ll)(S[j] - '0');
	}
}

int main()
{
	Input();

	cout << solve(0) << '\n';
}