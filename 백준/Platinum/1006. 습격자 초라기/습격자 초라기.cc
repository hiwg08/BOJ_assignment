#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

ll T, N, W, total = LLONG_MAX;

ll Arr_U[10001]{ 0 }, Arr_D[10001]{ 0 };

ll DP[10001][4]{ 0 };

ll store_u_l, store_u_r, store_d_l, store_d_r;

ll solve(ll state)
{
	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < 4; j++)
			DP[i][j] = 99999;
	}

	for (ll i = 0; i < N; i++)
	{
		if (i == 0)
		{
			if (state == 0 || state == 1)
				DP[i][0] = 1;

			if (state == 2)
				DP[i][0] = 0;

			if (state == 3)
			{
				DP[i][0] = 2;

				if (Arr_U[i] + Arr_D[i] <= W)
					DP[i][1] = 1;
			}
		}
		else if (i < N - 1)
		{
			DP[i][0] = min({ DP[i - 1][0], DP[i - 1][1], DP[i - 1][2], DP[i - 1][3] }) + 2;

			if (Arr_U[i] + Arr_U[i - 1] <= W && Arr_D[i] + Arr_D[i - 1] <= W)
				DP[i][1] = DP[i - 1][0];

			if (Arr_U[i] + Arr_D[i] <= W)
				DP[i][1] = min(DP[i][1], min({ DP[i - 1][0], DP[i - 1][1], DP[i - 1][2], DP[i - 1][3] }) + 1);

			if (Arr_U[i] + Arr_U[i - 1] <= W)
				DP[i][2] = min(DP[i - 1][0], DP[i - 1][3]) + 1;

			if (Arr_D[i] + Arr_D[i - 1] <= W)
				DP[i][3] = min(DP[i - 1][0], DP[i - 1][2]) + 1;
		}
		else
		{
			if (state == 3) // 하나도 비우지 않았을 때
			{
				DP[i][0] = min({ DP[i - 1][0], DP[i - 1][1], DP[i - 1][2], DP[i - 1][3] }) + 2;

				if (Arr_U[i] + Arr_U[i - 1] <= W && Arr_D[i] + Arr_D[i - 1] <= W)
					DP[i][1] = DP[i - 1][0];

				if (Arr_U[i] + Arr_D[i] <= W)
					DP[i][1] = min(DP[i][1], min({ DP[i - 1][0], DP[i - 1][1], DP[i - 1][2], DP[i - 1][3] }) + 1);

				if (Arr_U[i] + Arr_U[i - 1] <= W)
					DP[i][2] = min(DP[i - 1][0], DP[i - 1][3]) + 1;

				if (Arr_D[i] + Arr_D[i - 1] <= W)
					DP[i][3] = min(DP[i - 1][0], DP[i - 1][2]) + 1;
			}
			if (state == 0) // 위 지울 때 0, 3만 있으면 됨
			{
				DP[i][0] = min({ DP[i - 1][0], DP[i - 1][1], DP[i - 1][2], DP[i - 1][3] }) + 1;

				if (Arr_D[i] + Arr_D[i - 1] <= W)
					DP[i][3] = min(DP[i - 1][0], DP[i - 1][2]);
			}
			if (state == 1) // 아래 지울 때 0, 2만 있으면 됨
			{
				DP[i][0] = min({ DP[i - 1][0], DP[i - 1][1], DP[i - 1][2], DP[i - 1][3] }) + 1;

				if (Arr_U[i] + Arr_U[i - 1] <= W)
					DP[i][2] = min(DP[i - 1][0], DP[i - 1][3]);
			}
			if (state == 2) // 전부 비웠을 때
				return min({ DP[i - 1][0], DP[i - 1][1], DP[i - 1][2], DP[i - 1][3] });
		}
	}

	return min({ DP[N - 1][0], DP[N - 1][1], DP[N - 1][2], DP[N - 1][3] });
}

int main()
{
	fastio;

	cin >> T;

	while (T--)
	{
		total = LLONG_MAX;

		cin >> N >> W;

		for (ll i = 0; i < N; i++)
			cin >> Arr_U[i];

		for (ll i = 0; i < N; i++)
			cin >> Arr_D[i];

		store_u_l = Arr_U[0], store_u_r = Arr_U[N - 1], store_d_l = Arr_D[0], store_d_r = Arr_D[N - 1];

		if (Arr_U[0] + Arr_U[N - 1] <= W)
		{
			Arr_U[0] = 99999, Arr_U[N - 1] = 99999;
			total = min(total, solve(0) + 1);
			Arr_U[0] = store_u_l, Arr_U[N - 1] = store_u_r;
		}
		if (Arr_D[0] + Arr_D[N - 1] <= W)
		{
			Arr_D[0] = 99999, Arr_D[N - 1] = 99999;
			total = min(total, solve(1) + 1);
			Arr_D[0] = store_d_l, Arr_D[N - 1] = store_d_r;
		}
		if (Arr_U[0] + Arr_U[N - 1] <= W && Arr_D[0] + Arr_D[N - 1] <= W)
		{
			Arr_U[0] = 99999, Arr_U[N - 1] = 99999;
			Arr_D[0] = 99999, Arr_D[N - 1] = 99999;
			total = min(total, solve(2) + 2);
			Arr_U[0] = store_u_l, Arr_U[N - 1] = store_u_r;
			Arr_D[0] = store_d_l, Arr_D[N - 1] = store_d_r;
		}

		total = min(total, solve(3));

		cout << total << '\n';
	}
}