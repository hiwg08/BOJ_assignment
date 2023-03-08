#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, M, ans = INT_MAX, first_p, second_p;

ll dx[1002]{ 0 }, dy[1002]{ 0 };

ll DP[1010][1010]{ 0 };

pll trace[1010][1010];

vector<ll> total;

void solve()
{
	memset(DP, 0x7f, sizeof(DP));

	DP[0][0] = 0;

	DP[0][1] = abs(N - dx[1]) + abs(N - dy[1]);

	DP[1][0] = abs(1 - dx[1]) + abs(1 - dy[1]);

	for (ll i = 0; i <= M; i++) // 경찰차 1
	{
		for (ll j = 0; j <= M; j++) // 경찰차 2
		{
			if (i == j)
				continue;

			ll nxt = max(i, j) + 1;

			if (i == 0)
				dx[i] = 1, dy[i] = 1;
			if (j == 0)
				dx[j] = N, dy[j] = N;

			if (DP[nxt][j] > DP[i][j] + abs(dx[nxt] - dx[i]) + abs(dy[nxt] - dy[i]))
			{
				DP[nxt][j] = DP[i][j] + abs(dx[nxt] - dx[i]) + abs(dy[nxt] - dy[i]);
				trace[nxt][j] = { i, j };
			}
			if (DP[i][nxt] > DP[i][j] + abs(dx[nxt] - dx[j]) + abs(dy[nxt] - dy[j]))
			{
				DP[i][nxt] = DP[i][j] + abs(dx[nxt] - dx[j]) + abs(dy[nxt] - dy[j]);
				trace[i][nxt] = { i, j };
			}
		}
	}

	for (ll i = 0; i <= M - 1; i++)
	{
		ans = min(ans, DP[i][M]);
		ans = min(ans, DP[M][i]);
	}
}

void reconstruct(ll a, ll b, ll params)
{
	if (params == 0)
		return;
	
	a > b ? total.push_back(1) : total.push_back(2);

	reconstruct(trace[a][b].x, trace[a][b].y, params - 1);
}

int main()
{
	cin >> N >> M;

	for (ll i = 1; i <= M; i++)
		cin >> dx[i] >> dy[i];

	solve();

	cout << ans << '\n';

	for (ll i = 0; i <= M - 1; i++)
	{
		if (DP[i][M] == ans)
		{
			first_p = i, second_p = M;
			break;
		}
		if (DP[M][i] == ans)
		{
			first_p = M, second_p = i;
			break;
		}
	}

	reconstruct(first_p, second_p, M);

	reverse(total.begin(), total.end());

	for (auto e : total)
		cout << e << '\n';
}