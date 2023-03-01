#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, K, total;

vector<vector<ll>> V;

ll cpy[101][101]{ 0 };

ll dx[]{ 0, 1, 0, -1 };
ll dy[]{ -1, 0, 1, 0 };

void insert_min()
{
	ll M = LLONG_MAX;

	for (ll i = 0; i < N; i++)
		M = min(M, V[i][0]);

	for (ll i = 0; i < N; i++)
	{
		if (V[i][0] == M)
			V[i][0]++;
	}
}

void first_move()
{
	V[0][1] = V[0][0];

	for (ll i = 1; i < N; i++)
		V[i - 1][0] = V[i][0];

	V[N - 1][0] = -1;
}

void rotate_90(ll row, ll col, ll remain)
{
	memset(cpy, 0, sizeof(cpy));

	for (ll i = 0; i < row; i++)
	{
		for (ll j = 0; j < col; j++)
		{
			ll new_x = i;
			ll new_y = col - 1 - j;

			cpy[new_x][new_y] = V[j][i];
		}
	}

	for (ll i = 0; i < col; i++)
	{
		for (ll j = 0; j < row; j++)
			V[j][i + 1] = cpy[j][i];
	}

	for (ll i = col; i < col + remain; i++)
		V[i - col][0] = V[i][0];

	for (ll i = col + remain - 1, j = col; j > 0; i--, j--)
		V[i][0] = -1;
}

void rotate_180(ll row, ll col, ll remain, ll be)
{
	memset(cpy, 0, sizeof(cpy));

	for (ll i = 0; i < row; i++)
	{
		for (ll j = 0; j < col; j++)
		{
			ll new_x = col - 1 - j;
			ll new_y = row - 1 - i;

			cpy[new_x][new_y] = V[j][i];
		}
	}

	for (ll i = 0; i < row; i++)
	{
		for (ll j = 0; j < col; j++)
			V[j][i + be] = cpy[j][i];
	}

	for (ll k = 0; k < be; k++)
	{
		for (ll i = col; i < col + remain; i++)
			V[i - col][k] = V[i][k];
	}


	for (ll k = 0; k < be; k++)
	{
		for (ll i = col + remain - 1, j = col; j > 0; i--, j--)
			V[i][k] = -1;
	}
}

void move_fish()
{
	vector<vector<ll>> cpy = vector<vector<ll>>(101, vector<ll>(101, 0));

	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < N; j++)
		{
			if (V[j][i] != -1)
			{
				for (ll dir = 0; dir < 4; dir++)
				{
					ll nx = j + dx[dir], ny = i + dy[dir];

					if (nx < 0 || ny < 0 || nx >= N || ny >= N)
						continue;

					if (V[nx][ny] == -1)
						continue;

					ll diff = (V[j][i] - V[nx][ny]) / 5;

					if (diff > 0)
					{
						cpy[nx][ny] += diff;
						cpy[j][i] -= diff;
					}
				}
			}
		}
	}

	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < N; j++)
		{
			if (V[j][i] != -1)
				V[j][i] += cpy[j][i];
		}
	}
}

void sort_oe()
{
	vector<vector<ll>> cpy = vector<vector<ll>>(101, vector<ll>(101, -1));

	ll Idx = 0;

	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < N; j++)
		{
			if (V[i][j] == -1)
				break;
			cpy[Idx++][0] = V[i][j];
		}
	}

	V = cpy;
}

bool check()
{
	ll MI = LLONG_MAX, MA = LLONG_MIN;

	for (ll i = 0; i < N; i++)
		MI = min(MI, V[i][0]), MA = max(MA, V[i][0]);

	return abs(MI - MA) <= K;
}

void solve()
{
	while (true)
	{
		total++;

		insert_min();

		first_move();

		ll remain = N - 2, cnt = 2;

		rotate_90(cnt, cnt - 1, remain);

		bool chk = false;

		while (true)
		{
			remain -= cnt;

			if (cnt > remain)
				break;

			if (!chk)
			{
				rotate_90(cnt, cnt, remain);
				chk = true;
			}
			else
			{
				cnt++;

				if (cnt > remain)
					break;

				rotate_90(cnt, cnt - 1, remain);
				chk = false;
			}
		}

		move_fish();

		sort_oe();

		rotate_180(1, N / 2, N / 2, 1);

		rotate_180(2, N / 4, N / 4, 2);

		move_fish();

		sort_oe();

		if (check())
			break;
	}
}

void Input()
{
	cin >> N >> K;

	V = vector<vector<ll>>(101, vector<ll>(101, -1));

	for (ll i = 0, a; i < N; i++)
	{
		cin >> a;
		V[i][0] = a;
	}
}

int main()
{
	Input();

	solve();

	cout << total << '\n';
}