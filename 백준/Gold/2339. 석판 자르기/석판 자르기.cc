#include <bits/stdc++.h>
#define ll long long
#define o (ll)1

using namespace std;

ll DP[21][21][21][21][3]{ 0 };

ll N;

ll Arr[21][21]{ 0 };

ll row_j[21]{ 0 }, col_j[21]{ 0 }; // 각각 행, 열에 대한 정보

ll row_t[21]{ 0 }, col_t[21]{ 0 };

ll solve(ll sx, ll sy, ll ex, ll ey, ll state) // 0, 0, 8, 8로 했으니까....
{
	if (sx > ex || sy > ey)
		return 0;

	ll& ret = DP[sx][sy][ex][ey][state];

	if (ret != -1)
		return ret;

	ll cnt = 0;

	ret = 0;

	bool trash_vis = false;

	if (state == 0 || state == 1)
	{
		for (ll i = sx; i <= ex; i++) // sy ~ ey에 해당하는 구간에 대한 비트 마스킹
		{
			ll L = row_t[i];
			ll R = row_j[i];

			L = (L >> sy) & ((o << (ey - sy + 1)) - 1);

			R = (R >> sy) & ((o << (ey - sy + 1)) - 1);

			cnt += (ll)(__builtin_popcount(R));

			if ((ll)(__builtin_popcount(L)) != 0 && (ll)(__builtin_popcount(R)) == 0) // 이 때만 분할해야 한다.
			{
				trash_vis = true;
				ret += (solve(sx, sy, i - 1, ey, 2) * solve(i + 1, sy, ex, ey, 2));
			}
		}
	}
	
	if (state == 0 || state == 2)
	{
		for (ll i = sy; i <= ey; i++) // sx ~ ex에 해당하는 구간에 대한 비트 마스킹
		{
			ll L = col_t[i];
			ll R = col_j[i];

			L = (L >> sx) & ((o << (ex - sx + 1)) - 1);

			R = (R >> sx) & ((o << (ex - sx + 1)) - 1);

			cnt += (ll)(__builtin_popcount(R));

			if ((ll)(__builtin_popcount(L)) != 0 && (ll)(__builtin_popcount(R)) == 0) // 이 때만 분할해야 한다.
			{
				trash_vis = true;
				
				ret += (solve(sx, sy, ex, i - 1, 1) * solve(sx, i + 1, ex, ey, 1));
			}
		}
	}

	if (!trash_vis && cnt == 1)
		return ret = 1;

	return ret;

	// 맨 처음은 행 부터 탐색
}

void init()
{
	cin >> N;

	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < N; j++)
		{
			cin >> Arr[i][j];

			if (Arr[i][j] == 1)
				row_t[i] |= (o << j);

			else if (Arr[i][j] == 2)
				row_j[i] |= (o << j);
		}
	}

	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < N; j++)
		{
			if (Arr[j][i] == 1)
				col_t[i] |= (o << j);

			else if (Arr[j][i] == 2)
				col_j[i] |= (o << j);
		}
	}
}

int main()
{
	init();
	
	memset(DP, -1, sizeof(DP));

	ll ans = solve(0, 0, N - 1, N - 1, 0);

	if (ans == 0)
		ans = -1;

	cout << ans;
}